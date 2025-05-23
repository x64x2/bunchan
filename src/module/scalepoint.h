/*
 * scalepoint.h
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
#ifndef NOISE_MODULE_SCALEPOINT_H
#define NOISE_MODULE_SCALEPOINT_H

namespace noise
{

  namespace module
  {

    /// Default scaling factor applied to the @a x coordinate for the
  
    const double DEFAULT_SCALE_POINT_X = 1.0;

    /// Default scaling factor applied to the @a y coordinate for the
    /// noise::module::ScalePoint noise module.
    const double DEFAULT_SCALE_POINT_Y = 1.0;

    /// Default scaling factor applied to the @a z coordinate for the
    /// noise::module::ScalePoint noise module.
    const double DEFAULT_SCALE_POINT_Z = 1.0;

    /// Noise module that scales the coordinates of the input value before
    /// returning the output value from a source module.
    
    class ScalePoint: public Module
    {

      public:

        /// Constructor.
        ///
        /// The default scaling factor applied to the @a x coordinate is set
        /// to noise::module::DEFAULT_SCALE_POINT_X.
        ///
        /// The default scaling factor applied to the @a y coordinate is set
        /// to noise::module::DEFAULT_SCALE_POINT_Y.
        ///
        /// The default scaling factor applied to the @a z coordinate is set
        /// to noise::module::DEFAULT_SCALE_POINT_Z.
        ScalePoint ();

        virtual int GetSourceModuleCount () const
        {
          return 1;
        }

        virtual double GetValue (double x, double y, double z) const;
        /// @returns The scaling factor applied to the @a x coordinate.
        double GetXScale () const
        {
          return m_xScale;
        }
        /// @returns The scaling factor applied to the @a y coordinate.
        double GetYScale () const
        {
          return m_yScale;
        }
        /// @returns The scaling factor applied to the @a z coordinate.
        double GetZScale () const
        {
          return m_zScale;
        }

        /// @param scale The scaling factor to apply.
        
        void SetScale (double scale)
        {
          m_xScale = scale;
          m_yScale = scale;
          m_zScale = scale;
        }

        /// @param xScale The scaling factor to apply to the @a x coordinate.
        /// @param yScale The scaling factor to apply to the @a y coordinate.
        /// @param zScale The scaling factor to apply to the @a z coordinate.
       
        void SetScale (double xScale, double yScale, double zScale)
        {
          m_xScale = xScale;
          m_yScale = yScale;
          m_zScale = zScale;
        }

        /// @param xScale The scaling factor to apply to the @a x coordinate.
       
        void SetXScale (double xScale)
        {
          m_xScale = xScale;
        }

        /// @param yScale The scaling factor to apply to the @a y coordinate.
      
        void SetYScale (double yScale)
        {
          m_yScale = yScale;
        }

        /// @param zScale The scaling factor to apply to the @a z coordinate.
       
        void SetZScale (double zScale)
        {
          m_zScale = zScale;
        }

      protected:

        /// Scaling factor applied to the @a x coordinate of the input value.
        double m_xScale;

        /// Scaling factor applied to the @a y coordinate of the input value.
        double m_yScale;

        /// Scaling factor applied to the @a z coordinate of the input value.
        double m_zScale;

    }
  }

}


