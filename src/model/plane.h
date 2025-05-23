/*
 * plane.h
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
#include "../module/modulebase.h"

#ifndef NOISE_MODEL_PLANE_H
#define NOISE_MODEL_PLANE_H

namespace noise
{

  namespace model
  {

    /// Model that defines the surface of a plane.
    ///
    /// This model returns an output value from a noise module given the
    /// coordinates of an input value located on the surface of an ( @a x,
    /// @a z ) plane.
    class Plane
    {

      public:

        /// Constructor.
        Plane ();

        /// @param module The noise module that is used to generate the output
        /// values.
        Plane (const module::Module& module);

        /// @returns A reference to the noise module.
        /// @pre A noise module was passed to the SetModule() method.
        const module::Module& GetModule () const
        {
          assert (m_pModule != NULL);
          return *m_pModule;
        }
        /// @param x The @a x coordinate of the input value.
        /// @param z The @a z coordinate of the input value.
        ///
        /// @returns The output value from the noise module.
        ///
        /// @pre A noise module was passed to the SetModule() method.
        double GetValue (double x, double z) const;

        /// @param module The noise module that is used to generate the output
        /// values.
        void SetModule (const module::Module& module)
        {
          m_pModule = &module;
        }

      private:

        /// A pointer to the noise module used to generate the output values.
        const module::Module* m_pModule;

    }

  }

}

