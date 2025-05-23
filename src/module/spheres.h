/*
 * spheres.h
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

#ifndef NOISE_MODULE_SPHERES_H
#define NOISE_MODULE_SPHERES_H
namespace noise
{

  namespace module
  {

    /// Default frequency value for the noise::module::Spheres noise module.
    const double DEFAULT_SPHERES_FREQUENCY = 1.0;

    /// Noise module that outputs concentric spheres.
   
    /// This noise module outputs concentric spheres centered on the origin
    /// like the concentric rings of an onion.
    ///
    /// The first sphere has a radius of 1.0.  Each subsequent sphere has a
    /// radius that is 1.0 unit larger than the previous sphere.
        
    class Spheres: public Module
    {

      public:

        /// Constructor.
     
        Spheres ();

        /// @returns The frequency of the concentric spheres.
        
        double GetFrequency () const
        {
          return m_frequency;
        }

        virtual int GetSourceModuleCount () const
        {
          return 0;
        }

        virtual double GetValue (double x, double y, double z) const;
        /// @param frequency The frequency of the concentric spheres.
      
        void SetFrequency (double frequency)
        {
          m_frequency = frequency;
        }

      protected:

        /// Frequency of the concentric spheres.
        double m_frequency;

    }

  }

}

