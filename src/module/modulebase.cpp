/*
 * modulebase.cpp
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


#include "modulebase.h"

using namespace noise::module;

Module::Module (int sourceModuleCount)
{
  m_pSourceModule = NULL;

  /// Create an array of pointers to all source modules required by this
  /// noise module.  Set these pointers to NULL.
  if (sourceModuleCount > 0) {
    m_pSourceModule = new const Module*[sourceModuleCount];
    for (int i = 0; i < sourceModuleCount; i++) {
      m_pSourceModule[i] = NULL;
    }
  } else {
    m_pSourceModule = NULL;
  }
}

Module::~Module ()
{
  delete[] m_pSourceModule;
}
