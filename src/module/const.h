/*
 * const.h
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

#ifndef NOISE_MODULE_CONST_H
#define NOISE_MODULE_CONST_H

namespace noise
{

  namespace module
  {
   /// default constant value for the noise::module::Const noise module.
    const double DEFAULT_CONST_VALUE = 0.0;

    /// noise module that outputs a constant value.
    class Const: public Module
    {

      public:
        /// The default constant value is set to
        /// noise::module::DEFAULT_CONST_VALUE.
        Const ();

        /// @returns The constant output value for this noise module.
        double GetConstValue () const
        {
          return m_constValue;
        }

        virtual int GetSourceModuleCount () const
        {
          return 0;
        }

        virtual double GetValue (double x, double y, double z) const
        {
          return m_constValue;
        }

        /// Sets the constant output value for this noise module.
        /// @param constValue The constant output value for this noise module.
        void SetConstValue (double constValue)
        {
          m_constValue = constValue;
        }

      protected:

        /// Constant value.
        double m_constValue;
        
   }
}

 
