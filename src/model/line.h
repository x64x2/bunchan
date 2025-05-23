/*
 * line.h
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



#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "../module/modulebase.h"

#ifndef NOISE_MODEL_LINE_H
#define NOISE_MODEL_LINE_H

namespace noise
{

  namespace model
  {
    /// Model that defines the displacement of a line segment.
    
    class Line
    {

      public:

        /// Constructor.
        Line ();

        /// @param module The noise module that is used to generate the output
        /// values.
        Line (const module::Module& module);

        /// @returns
        /// - @a true if the value is to be attenuated
        /// - @a false if not.
        bool GetAttenuate () const
        {
          return m_attenuate;
        }

        /// @returns A reference to the noise module.
        ///
        /// @pre A noise module was passed to the SetModule() method.
        const module::Module& GetModule () const
        {
          assert (m_pModule != NULL);
          return *m_pModule;
        }

        /// @param p The distance along the line segment (ranges from 0.0
        /// to 1.0)
        ///
        /// @returns The output value from the noise module.
        ///
        /// @pre A noise module was passed to the SetModule() method.
        /// @pre The start and end points of the line segment were specified.
        double GetValue (double p) const;

        /// @param att A flag that specifies whether the output value is to be
        void SetAttenuate (bool att)
        {
          m_attenuate = att;
        }

        /// @param x x coordinate of the end position.
        /// @param y y coordinate of the end position.
        /// @param z z coordinate of the end position.
        void SetEndPoint (double x, double y, double z)
        {
          m_x1 = x;
          m_y1 = y;
          m_z1 = z;
        }

        /// @param module The noise module that is used to generate the output
        /// values.
        void SetModule (const module::Module& module)
        {
          m_pModule = &module;
        }
        
        /// @param x x coordinate of the start position.
        /// @param y y coordinate of the start position.
        /// @param z z coordinate of the start position.
        void SetStartPoint (double x, double y, double z)
        {
          m_x0 = x;
          m_y0 = y;
          m_z0 = z;
        }

      private:

        /// A flag that specifies whether the value is to be attenuated
        /// (moved toward 0.0) as the ends of the line segment are approached.
        bool m_attenuate;

        /// A pointer to the noise module used to generate the output values.
        const module::Module* m_pModule;

        /// @a x coordinate of the start of the line segment.
        double m_x0;

        /// @a x coordinate of the end of the line segment.
        double m_x1;

        /// @a y coordinate of the start of the line segment.
        double m_y0;

        /// @a y coordinate of the end of the line segment.
        double m_y1;

        /// @a z coordinate of the start of the line segment.
        double m_z0;

        /// @a z coordinate of the end of the line segment.
        double m_z1;

    }

  }

}

