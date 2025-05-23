/*
 * checkerboard.h
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

#ifndef NOISE_MODULE_CHECKERBOARD_H
#define NOISE_MODULE_CHECKERBOARD_H

namespace noise
{

  namespace module
  {
    /// @addtogroup generatormodules
 
    /// This noise module outputs unit-sized blocks of alternating values.
    /// The values of these blocks alternate between -1.0 and +1.0.
    
    class Checkerboard: public Module
    {

      public:

        /// Constructor.
        Checkerboard ();

        virtual int GetSourceModuleCount () const
        {
        return 0;
        }

        virtual double GetValue (double x, double y, double z) const;

    }
 }
