/*
 * exponent.h
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
#ifndef NOISE_MODULE_EXPONENT_H
#define NOISE_MODULE_EXPONENT_H

namespace noise
{

  namespace module
  {

    /// Default exponent for the noise::module::Exponent noise module.
    const double DEFAULT_EXPONENT = 1.0;

    /// Noise module that maps the output value from a source module onto an
    
    class Exponent: public Module
    {

      public:

        /// The default exponent is set to noise::module::DEFAULT_EXPONENT.
        Exponent ();

        /// @returns The exponent value.
        /// Because most noise modules will output values that range from -1.0
        /// to +1.0, this noise module first normalizes this output value (the
        /// range becomes 0.0 to 1.0), maps that value onto an exponential
        /// curve, then rescales that value back to the original range.
        double GetExponent () const
        {
          return m_exponent;
        }

        virtual int GetSourceModuleCount () const
        {
          return 1;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// @param exponent The exponent value.
        /// Because most noise modules will output values that range from -1.0
        /// to +1.0, this noise module first normalizes this output value (the
        /// range becomes 0.0 to 1.0), maps that value onto an exponential
        /// curve, then rescales that value back to the original range.
        void SetExponent (double exponent)
        {
          m_exponent = exponent;
        }

      protected:

        /// Exponent to apply to the output value from the source module.
        double m_exponent;

    }
}
