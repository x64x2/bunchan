/*
 * rotatepoint.h
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

#ifndef NOISE_MODULE_ROTATEPOINT_H
#define NOISE_MODULE_ROTATEPOINT_H

namespace noise
{

  namespace module
  {
    /// Default @a x rotation angle for the noise::module::RotatePoint noise
    /// module.
    const double DEFAULT_ROTATE_X = 0.0;

    /// Default @a y rotation angle for the noise::module::RotatePoint noise
   
    const double DEFAULT_ROTATE_Y = 0.0;

    /// Default @a z rotation angle for the noise::module::RotatePoint noise
   
    const double DEFAULT_ROTATE_Z = 0.0;

    /// Noise module that rotates the input value around the origin before
    /// returning the output value from a source module.
    ///
    /// @image html modulerotatepoint.png
    ///
    /// The GetValue() method rotates the coordinates of the input value
  
    /// The coordinate system of the input value is assumed to be
    /// "left-handed" (@a x increases to the right, @a y increases upward,
    /// and @a z increases inward.)
  
    class RotatePoint: public Module
    {

      public:

        RotatePoint ();

        virtual int GetSourceModuleCount () const
        {
          return 1;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// Returns the rotation angle around the @a x axis to apply to the
        /// input value.
        ///
        /// @returns The rotation angle around the @a x axis, in degrees.
        double GetXAngle () const
        {
          return m_xAngle;
        }

        /// @returns The rotation angle around the @a y axis, in degrees.
        double GetYAngle () const
        {
          return m_yAngle;
        }

        /// @returns The rotation angle around the @a z axis, in degrees.
        double GetZAngle () const
        {
          return m_zAngle;
        }

        /// @param xAngle The rotation angle around the @a x axis, in degrees.
        /// @param yAngle The rotation angle around the @a y axis, in degrees.
        /// @param zAngle The rotation angle around the @a z axis, in degrees.
      
        void SetAngles (double xAngle, double yAngle, double zAngle);

        /// @param xAngle The rotation angle around the @a x axis, in degrees.
      
        void SetXAngle (double xAngle)
        {
          SetAngles (xAngle, m_yAngle, m_zAngle);
        }

        /// @param yAngle The rotation angle around the @a y axis, in degrees.
        
        void SetYAngle (double yAngle)
        {
          SetAngles (m_xAngle, yAngle, m_zAngle);
        }

        /// @param zAngle The rotation angle around the @a z axis, in degrees.
       
        void SetZAngle (double zAngle)
        {
          SetAngles (m_xAngle, m_yAngle, zAngle);
        }

      protected:

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_x1Matrix;

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_x2Matrix;

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_x3Matrix;

        /// @a x rotation angle applied to the input value, in degrees.
        double m_xAngle;

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_y1Matrix;

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_y2Matrix;

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_y3Matrix;

        /// @a y rotation angle applied to the input value, in degrees.
        double m_yAngle;

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_z1Matrix;

        /// An entry within the 3x3 rotation matrix used for rotating the
       
        double m_z2Matrix;

        /// An entry within the 3x3 rotation matrix used for rotating the
       ///
        double m_z3Matrix;

        /// @a z rotation angle applied to the input value, in degrees.
        double m_zAngle;

    }
  }

}

