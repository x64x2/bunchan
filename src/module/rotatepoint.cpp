/*
 * rotatepoint.cpp
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


#include "../mathconsts.h"
#include "rotatepoint.h"

using namespace noise::module;

RotatePoint::RotatePoint ():
  Module (GetSourceModuleCount ())
{
  SetAngles (DEFAULT_ROTATE_X, DEFAULT_ROTATE_Y, DEFAULT_ROTATE_Z);
}

double RotatePoint::GetValue (double x, double y, double z) const
{
  assert (m_pSourceModule[0] != NULL);

  double nx = (m_x1Matrix * x) + (m_y1Matrix * y) + (m_z1Matrix * z);
  double ny = (m_x2Matrix * x) + (m_y2Matrix * y) + (m_z2Matrix * z);
  double nz = (m_x3Matrix * x) + (m_y3Matrix * y) + (m_z3Matrix * z);
  return m_pSourceModule[0]->GetValue (nx, ny, nz);
}

void RotatePoint::SetAngles (double xAngle, double yAngle,
  double zAngle)
{
  double xCos, yCos, zCos, xSin, ySin, zSin;
  xCos = cos (xAngle * DEG_TO_RAD);
  yCos = cos (yAngle * DEG_TO_RAD);
  zCos = cos (zAngle * DEG_TO_RAD);
  xSin = sin (xAngle * DEG_TO_RAD);
  ySin = sin (yAngle * DEG_TO_RAD);
  zSin = sin (zAngle * DEG_TO_RAD);

  m_x1Matrix = ySin * xSin * zSin + yCos * zCos;
  m_y1Matrix = xCos * zSin;
  m_z1Matrix = ySin * zCos - yCos * xSin * zSin;
  m_x2Matrix = ySin * xSin * zCos - yCos * zSin;
  m_y2Matrix = xCos * zCos;
  m_z2Matrix = -yCos * xSin * zCos - ySin * zSin;
  m_x3Matrix = -ySin * xCos;
  m_y3Matrix = xSin;
  m_z3Matrix = yCos * xCos;

  m_xAngle = xAngle;
  m_yAngle = yAngle;
  m_zAngle = zAngle;
}
