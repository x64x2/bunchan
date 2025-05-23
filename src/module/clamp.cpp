/*
 * clamp.cpp
 * 
 * Copyright 2025 x64x2 <x64x2@mango>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "clamp.h"

using namespace noise::module;

Clamp::Clamp ():
  Module (GetSourceModuleCount ()),
  m_lowerBound (DEFAULT_CLAMP_LOWER_BOUND),
  m_upperBound (DEFAULT_CLAMP_UPPER_BOUND)
{
}

double Clamp::GetValue (double x, double y, double z) const
{
  assert (m_pSourceModule[0] != NULL);

  double value = m_pSourceModule[0]->GetValue (x, y, z);
  if (value < m_lowerBound) {
    return m_lowerBound;
  } else if (value > m_upperBound) {
    return m_upperBound;
  } else {
    return value;
  }
}

void Clamp::SetBounds (double lowerBound, double upperBound)
{
  assert (lowerBound < upperBound);

  m_lowerBound = lowerBound;
  m_upperBound = upperBound;
}
