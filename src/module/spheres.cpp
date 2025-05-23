/*
 * spheres.cpp
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


#include "../misc.h"
#include "spheres.h"

using namespace noise::module;

Spheres::Spheres ():
  Module (GetSourceModuleCount ()),
  m_frequency (DEFAULT_SPHERES_FREQUENCY)
{
}

double Spheres::GetValue (double x, double y, double z) const
{
  x *= m_frequency;
  y *= m_frequency;
  z *= m_frequency;

  double distFromCenter = sqrt (x * x + y * y + z * z);
  double distFromSmallerSphere = distFromCenter - floor (distFromCenter);
  double distFromLargerSphere = 1.0 - distFromSmallerSphere;
  double nearestDist = GetMin (distFromSmallerSphere, distFromLargerSphere);
  return 1.0 - (nearestDist * 4.0); // Puts it in the -1.0 to +1.0 range.
}
