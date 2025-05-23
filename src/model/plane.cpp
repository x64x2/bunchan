/*
 * plane.cpp
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


#include "plane.h"

using namespace noise;
using namespace noise::model;

Plane::Plane ():
  m_pModule (NULL)
{
}

Plane::Plane (const module::Module& module) :
  m_pModule( &module)
{
}

/// this was trivial.
double Plane::GetValue (double x, double z) const
{
  assert (m_pModule != NULL);
  
  return m_pModule->GetValue (x, 0, z);
}
