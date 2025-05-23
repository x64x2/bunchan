/*
 * turbulence.cpp
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

#include "turbulence.h"

using namespace noise::module;

Turbulence::Turbulence ():
  Module (GetSourceModuleCount ()),
  m_power (DEFAULT_TURBULENCE_POWER)
{
  SetSeed (DEFAULT_TURBULENCE_SEED);
  SetFrequency (DEFAULT_TURBULENCE_FREQUENCY);
  SetRoughness (DEFAULT_TURBULENCE_ROUGHNESS);
}

double Turbulence::GetFrequency () const
{
  /// Since each noise::module::Perlin noise module has the same frequency, it
  /// does not matter which module we use to retrieve the frequency.
  return m_xDistortModule.GetFrequency ();
}

int Turbulence::GetSeed () const
{
  return m_xDistortModule.GetSeed ();
}

double Turbulence::GetValue (double x, double y, double z) const
{
  assert (m_pSourceModule[0] != NULL);

  /// Get the values from the three noise::module::Perlin noise modules and
  /// add each value to each coordinate of the input value.  There are also
  /// some offsets added to the coordinates of the input values. 
  double x0, y0, z0;
  double x1, y1, z1;
  double x2, y2, z2;
  x0 = x + (12414.0 / 65536.0);
  y0 = y + (65124.0 / 65536.0);
  z0 = z + (31337.0 / 65536.0);
  x1 = x + (26519.0 / 65536.0);
  y1 = y + (18128.0 / 65536.0);
  z1 = z + (60493.0 / 65536.0);
  x2 = x + (53820.0 / 65536.0);
  y2 = y + (11213.0 / 65536.0);
  z2 = z + (44845.0 / 65536.0);
  double xDistort = x + (m_xDistortModule.GetValue (x0, y0, z0)
    * m_power);
  double yDistort = y + (m_yDistortModule.GetValue (x1, y1, z1)
    * m_power);
  double zDistort = z + (m_zDistortModule.GetValue (x2, y2, z2)
    * m_power);

  /// Retrieve the output value at the offsetted input value instead of the
  ///original input value.
  return m_pSourceModule[0]->GetValue (xDistort, yDistort, zDistort);
}

void Turbulence::SetSeed (int seed)
{
  /// Set the seed of each noise::module::Perlin noise modules.  To prevent any
  /// sort of weird artifacting, use a slightly different seed for each noise
  /// module.
  m_xDistortModule.SetSeed (seed    );
  m_yDistortModule.SetSeed (seed + 1);
  m_zDistortModule.SetSeed (seed + 2);
}
