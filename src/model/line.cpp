/*
 * line.cpp
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


#include "line.h"

using namespace noise;
using namespace noise::model;

Line::Line ():
  m_pModule (NULL),
  m_attenuate (true),
  m_x0 (0.0),
  m_y0 (0.0),
  m_z0 (0.0),
  m_x1 (1.0),
  m_y1 (1.0),
  m_z1 (1.0)
{
}

Line::Line (const module::Module& module):
  m_pModule (&module),
  m_attenuate (true),
  m_x0 (0.0),
  m_y0 (0.0),
  m_z0 (0.0),
  m_x1 (1.0),
  m_y1 (1.0),
  m_z1 (1.0)
{
}

double Line::GetValue (double p) const
{
  assert (m_pModule != NULL);

  double x = (m_x1 - m_x0) * p + m_x0;
  double y = (m_y1 - m_y0) * p + m_y0;
  double z = (m_z1 - m_z0) * p + m_z0;
  double value = m_pModule->GetValue (x, y, z);

  if (m_attenuate) {
    return p * (1.0 - p) * 4 * value;
  } else {
    return value;
  }
}
