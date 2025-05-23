/*
 * sphere.cpp
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


#include "../latlon.h"
#include "sphere.h"

using namespace noise;
using namespace noise::model;

Sphere::Sphere ():
  m_pModule (NULL)
{
}

Sphere::Sphere (const module::Module& module):
  m_pModule (&module)
{
}

double Sphere::GetValue (double lat, double lon) const
{
  assert (m_pModule != NULL);

  double x, y, z;
  LatLonToXYZ (lat, lon, x, y, z);
  return m_pModule->GetValue (x, y, z);
}
