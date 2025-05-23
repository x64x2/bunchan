/*
 * voronoi.h
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

#ifndef NOISE_MODULE_VORONOI_H
#define NOISE_MODULE_VORONOI_H

namespace noise
{

  namespace module
  {
    /// Default displacement to apply to each cell for the
    /// noise::module::Voronoi noise module.
    const double DEFAULT_VORONOI_DISPLACEMENT = 1.0;

    /// Default frequency of the seed points for the noise::module::Voronoi
    /// noise module.
    const double DEFAULT_VORONOI_FREQUENCY = 1.0;

    /// Default seed of the noise function for the noise::module::Voronoi
    /// noise module.
    const int DEFAULT_VORONOI_SEED = 0;

    /// Noise module that outputs Voronoi cells.
    ///
    /// @image html modulevoronoi.png
    ///
   
    /// This noise module requires no source modules.
    class Voronoi: public Module
    {

      public:

        /// Constructor.
        Voronoi ();

      
        /// @param enable Specifies whether to apply the distance to the
        /// output value or not.
       
        void EnableDistance (bool enable = true)
        {
          m_enableDistance = enable;
        }

        /// @returns The displacement value of the Voronoi cells.
        double GetDisplacement () const
        {
          return m_displacement;
        }

     
        /// @returns The frequency of the seed points.
        double GetFrequency () const
        {
          return m_frequency;
        }

        virtual int GetSourceModuleCount () const
        {
          return 0;
        }

        /// @returns The seed value.
     
        int GetSeed () const
        {
          return m_seed;
        }

      
        /// @returns
        /// - @a true if the distance is applied to the output value.
        /// - @a false if not.
      
        bool IsDistanceEnabled () const
        {
          return m_enableDistance;
        }

        virtual double GetValue (double x, double y, double z) const;

       
        /// @param displacement The displacement value of the Voronoi cells.
       
        void SetDisplacement (double displacement)
        {
          m_displacement = displacement;
        }

        /// @param frequency The frequency of the seed points.
        
        void SetFrequency (double frequency)
        {
          m_frequency = frequency;
        }

  
        /// @param seed The seed value.
        
        void SetSeed (int seed)
        {
          m_seed = seed;
        }

      protected:

        /// Scale of the random displacement to apply to each Voronoi cell.
        double m_displacement;

        /// Determines if the distance from the nearest seed point is applied to
        bool m_enableDistance;

        /// Frequency of the seed points.
        double m_frequency;

        /// Seed value used by the coherent-noise function to determine the
        /// positions of the seed points.
        int m_seed;

    }

  }

}


