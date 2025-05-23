/*
 * turbulence.h
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


#include "perlin.h"

#ifndef NOISE_MODULE_TURBULENCE_H
#define NOISE_MODULE_TURBULENCE_H

namespace noise
{

  namespace module 
  {
    /// Default frequency for the noise::module::Turbulence noise module.
    const double DEFAULT_TURBULENCE_FREQUENCY = DEFAULT_PERLIN_FREQUENCY;

    /// Default power for the noise::module::Turbulence noise module.
    const double DEFAULT_TURBULENCE_POWER = 1.0;

    /// Default roughness for the noise::module::Turbulence noise module.
    const int DEFAULT_TURBULENCE_ROUGHNESS = 3;

    /// Default noise seed for the noise::module::Turbulence noise module.
    const int DEFAULT_TURBULENCE_SEED = DEFAULT_PERLIN_SEED;

    /// Noise module that randomly displaces the input value before
    /// returning the output value from a source module.
  
   
    /// This noise module requires one source module.
    class Turbulence: public Module
    {

      public:

        /// Constructor.
        ///
        /// The default frequency is set to
        /// noise::module::DEFAULT_TURBULENCE_FREQUENCY.
        ///    
        /// The default power is set to
        /// noise::module::DEFAULT_TURBULENCE_POWER.
        ///
        /// The default roughness is set to
        /// noise::module::DEFAULT_TURBULENCE_ROUGHNESS.
        ///
        /// The default seed value is set to
        /// noise::module::DEFAULT_TURBULENCE_SEED.
        Turbulence ();

        /// Returns the frequency of the turbulence.
        ///
        /// @returns The frequency of the turbulence.
        ///
        /// The frequency of the turbulence determines how rapidly the
        /// displacement amount changes.
        double GetFrequency () const;

        /// Returns the power of the turbulence.
        ///
        /// @returns The power of the turbulence.
        ///
        /// The power of the turbulence determines the scaling factor that is
        /// applied to the displacement amount.
        double GetPower () const
        {
          return m_power;
        }

        /// Returns the roughness of the turbulence.
        ///
        /// @returns The roughness of the turbulence.
        ///
        /// The roughness of the turbulence determines the roughness of the
        /// changes to the displacement amount.  Low values smoothly change
        /// the displacement amount.  High values roughly change the
        /// displacement amount, which produces more "kinky" changes.
        int GetRoughnessCount () const
        {
          return m_xDistortModule.GetOctaveCount ();
        }

        /// Returns the seed value of the internal Perlin-noise modules that
        /// are used to displace the input values.
        ///
        /// @returns The seed value.
        ///
        /// Internally, there are three noise::module::Perlin noise modules
        /// that displace the input value; one for the @a x, one for the @a y,
        /// and one for the @a z coordinate.  
        int GetSeed () const;

        virtual int GetSourceModuleCount () const
        {
          return 1;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// Sets the frequency of the turbulence.
        ///
        /// @param frequency The frequency of the turbulence.
        ///
        /// The frequency of the turbulence determines how rapidly the
        /// displacement amount changes.
        void SetFrequency (double frequency)
        {
          // Set the frequency of each Perlin-noise module.
          m_xDistortModule.SetFrequency (frequency);
          m_yDistortModule.SetFrequency (frequency);
          m_zDistortModule.SetFrequency (frequency);
        }

        /// Sets the power of the turbulence.
        ///
        /// @param power The power of the turbulence.
        ///
        /// The power of the turbulence determines the scaling factor that is
        /// applied to the displacement amount.
        void SetPower (double power)
        {
          m_power = power;
        }

        /// Sets the roughness of the turbulence.
        ///
        /// @param roughness The roughness of the turbulence.
        ///
        /// The roughness of the turbulence determines the roughness of the
        /// changes to the displacement amount.  Low values smoothly change
        /// the displacement amount.  High values roughly change the
        /// displacement amount, which produces more "kinky" changes.
        ///
        /// Internally, there are three noise::module::Perlin noise modules
        /// that displace the input value; one for the @a x, one for the @a y,
        /// and one for the @a z coordinate.  The roughness value is equal to
        /// the number of octaves used by the noise::module::Perlin noise
        /// modules.
        void SetRoughness (int roughness)
        {
          // Set the octave count for each Perlin-noise module.
          m_xDistortModule.SetOctaveCount (roughness);
          m_yDistortModule.SetOctaveCount (roughness);
          m_zDistortModule.SetOctaveCount (roughness);
        }

        /// Sets the seed value of the internal noise modules that are used to
        /// displace the input values.
        ///
        /// @param seed The seed value.
        ///
        /// Internally, there are three noise::module::Perlin noise modules
        /// that displace the input value; one for the @a x, one for the @a y,
        /// and one for the @a z coordinate.  This noise module assigns the
        /// following seed values to the noise::module::Perlin noise modules:
        /// - It assigns the seed value (@a seed + 0) to the @a x noise module.
        /// - It assigns the seed value (@a seed + 1) to the @a y noise module.
        /// - It assigns the seed value (@a seed + 2) to the @a z noise module.
        void SetSeed (int seed);

      protected:

        /// The power (scale) of the displacement.
        double m_power;

        /// Noise module that displaces the @a x coordinate.
        Perlin m_xDistortModule;

        /// Noise module that displaces the @a y coordinate.
        Perlin m_yDistortModule;

        /// Noise module that displaces the @a z coordinate.
        Perlin m_zDistortModule;

    };

    /// @}

    /// @}

    /// @}

  }

}

#endif
