/*
 * scalebias.h
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

#ifndef NOISE_MODULE_SCALEBIAS_H
#define NOISE_MODULE_SCALEBIAS_H

namespace noise
{

  namespace module
  {

    /// Default bias for the noise::module::ScaleBias noise module.
    const double DEFAULT_BIAS = 0.0;

    /// Default scale for the noise::module::ScaleBias noise module.
    const double DEFAULT_SCALE = 1.0;

    /// Noise module that applies a scaling factor and a bias to the output
    /// value from a source module.
  
    /// The GetValue() method retrieves the output value from the source
    /// module, multiplies it with a scaling factor, adds a bias to it, then
  
    class ScaleBias: public Module
    {

      public:
        /// The default bias is set to noise::module::DEFAULT_BIAS.
        /// The default scaling factor is set to noise::module::DEFAULT_SCALE.
        ScaleBias ();

        /// @returns The bias to apply.
        
        double GetBias () const
        {
          return m_bias;
        }
        /// @returns The scaling factor to apply.
       
        double GetScale () const
        {
          return m_scale;
        }

        virtual int GetSourceModuleCount () const
        {
          return 1;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// @param bias The bias to apply.
       
        void SetBias (double bias)
        {
          m_bias = bias;
        }
        /// @param scale The scaling factor to apply.
       
        void SetScale (double scale)
        {
          m_scale = scale;
        }

      protected:

        /// Bias to apply to the scaled output value from the source module.
        double m_bias;

        /// Scaling factor to apply to the output value from the source
        double m_scale;

    }
  }

}
