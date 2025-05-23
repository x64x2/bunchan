/*
 * select.h
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

#ifndef NOISE_MODULE_SELECT_H
#define NOISE_MODULE_SELECT_H

namespace noise
{

  namespace module
  {
    /// Default edge-falloff value for the noise::module::Select noise module.
    const double DEFAULT_SELECT_EDGE_FALLOFF = 0.0;

    /// Default lower bound of the selection range for the
    /// noise::module::Select noise module.
    const double DEFAULT_SELECT_LOWER_BOUND = -1.0;

    /// Default upper bound of the selection range for the
    /// noise::module::Select noise module.
    const double DEFAULT_SELECT_UPPER_BOUND = 1.0;

    /// Noise module that outputs the value selected from one of two source
    /// modules chosen by the output value from a control module.
    class Select: public Module
    {

      public:

        /// Constructor
        Select ();
     
        /// @returns A reference to the control module.
        ///
        /// @pre A control module has been added to this noise module via a
        /// call to SetSourceModule() or SetControlModule().
        ///
        /// @throw noise::ExceptionNoModule See the preconditions for more
        /// information.
     
        const Module& GetControlModule () const
        {
          if (m_pSourceModule == NULL || m_pSourceModule[2] == NULL) {
            throw noise::ExceptionNoModule ();
          }
          return *(m_pSourceModule[2]);
        }
        /// @returns The falloff value at the edge transition.
        ///
        /// The falloff value is the width of the edge transition at either
        /// edge of the selection range.
        ///
        /// By default, there is an abrupt transition between the output
        /// values from the two source modules at the selection-range
        /// boundary.
        double GetEdgeFalloff () const
        {
          return m_edgeFalloff;
        }

        /// @returns The lower bound of the selection range.
       
        double GetLowerBound () const
        {
          return m_lowerBound;
        }

        virtual int GetSourceModuleCount () const
        {
          return 3;
        }

        /// @returns The upper bound of the selection range.
      
        double GetUpperBound () const
        {
          return m_upperBound;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// @param lowerBound The lower bound.
        /// @param upperBound The upper bound.
        ///
        /// @pre The lower bound must be less than or equal to the upper
        /// bound.
        ///
        /// @throw noise::ExceptionInvalidParam An invalid parameter was
        /// specified; see the preconditions for more information.
        void SetBounds (double lowerBound, double upperBound);

        /// @param controlModule The control module.
        ///
        /// The control module determines the output value to select.  If the
        /// output value from the control module is within a range of values
        
        void SetControlModule (const Module& controlModule)
        {
          assert (m_pSourceModule != NULL);
          m_pSourceModule[2] = &controlModule;
        }

       
        /// @param edgeFalloff The falloff value at the edge transition.
        ///
        /// The falloff value is the width of the edge transition at either
        /// edge of the selection range.
        ///
        /// By default, there is an abrupt transition between the values from
        /// the two source modules at the boundaries of the selection range.
        .
        void SetEdgeFalloff (double edgeFalloff);

      protected:

        /// Edge-falloff value.
        double m_edgeFalloff;

        /// Lower bound of the selection range.
        double m_lowerBound;

        /// Upper bound of the selection range.
        double m_upperBound;

    }
  }

}
