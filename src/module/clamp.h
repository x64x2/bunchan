/*
 * clamp.h
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

#ifndef NOISE_MODULE_CLAMP_H
#define NOISE_MODULE_CLAMP_H

namespace noise
{

  namespace module
  {
    /// Default lower bound of the clamping range for the noise::module::Clamp
    const double DEFAULT_CLAMP_LOWER_BOUND = -1.0;

    /// Default upper bound of the clamping range for the noise::module::Clamp
    const double DEFAULT_CLAMP_UPPER_BOUND = 1.0;

    /// Noise module that clamps the output value from a source module to a
    /// range of values.
    /// If the output value from the source module is less than the lower
    /// bound of the clamping range, this noise module clamps that value to
    /// the lower bound.  If the output value from the source module is
    /// greater than the upper bound of the clamping range, this noise module
    /// clamps that value to the upper bound.
    ///
    /// To specify the upper and lower bounds of the clamping range, call the
    /// SetBounds() method.
    ///
    /// This noise module requires one source module.
    class Clamp: public Module
    {

      public:

        /// The default lower bound of the clamping range is set to
        /// noise::module::DEFAULT_CLAMP_LOWER_BOUND.
        /// The default upper bound of the clamping range is set to
        /// noise::module::DEFAULT_CLAMP_UPPER_BOUND.
        Clamp ();

        /// Returns the lower bound of the clamping range.
     
        /// If the output value from the source module is less than the lower
        /// bound of the clamping range, this noise module clamps that value
        /// to the lower bound.
        double GetLowerBound () const
        {
          return m_lowerBound;
        }

        virtual int GetSourceModuleCount () const
        {
          return 1;
        }

        ///  If the output value from the source module is greater than the
        /// upper bound of the clamping range, this noise module clamps that
        /// value to the upper bound.
        double GetUpperBound () const
        {
          return m_upperBound;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// Sets the lower and upper bounds of the clamping range.
        
        /// If the output value from the source module is less than the lower
        /// bound of the clamping range, this noise module clamps that value
        /// to the lower bound.  If the output value from the source module
        /// is greater than the upper bound of the clamping range, this noise
        /// module clamps that value to the upper bound.
        void SetBounds (double lowerBound, double upperBound);

      protected:

        /// Lower bound of the clamping range.
        double m_lowerBound;

        /// Upper bound of the clamping range.
        double m_upperBound;

    }
}
