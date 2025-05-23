/*
 * cache.cpp
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

#include "cache.h"

using namespace noise::module;

Cache::Cache ():
  Module (GetSourceModuleCount ()),
  m_isCached (false)
{
}

double Cache::GetValue (double x, double y, double z) const
{
  assert (m_pSourceModule[0] != NULL);

  if (!(m_isCached && x == m_xCache && y == m_yCache && z == m_zCache)) {
    m_cachedValue = m_pSourceModule[0]->GetValue (x, y, z);
    m_xCache = x;
    m_yCache = y;
    m_zCache = z;
  }
  m_isCached = true;
  return m_cachedValue;
}
