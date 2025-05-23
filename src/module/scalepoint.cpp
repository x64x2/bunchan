/*
 * scalepoint.cpp
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

#include "scalepoint.h"

using namespace noise::module;

ScalePoint::ScalePoint ():
  Module (GetSourceModuleCount ()),
  m_xScale (DEFAULT_SCALE_POINT_X),
  m_yScale (DEFAULT_SCALE_POINT_Y),
  m_zScale (DEFAULT_SCALE_POINT_Z)
{
}

double ScalePoint::GetValue (double x, double y, double z) const
{
  assert (m_pSourceModule[0] != NULL);

  return m_pSourceModule[0]->GetValue (x * m_xScale, y * m_yScale,
    z * m_zScale);
}
