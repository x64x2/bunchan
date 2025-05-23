/*
 * ridgedmulti.h
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

#ifndef NOISE_MODULE_RIDGEDMULTI_H
#define NOISE_MODULE_RIDGEDMULTI_H

namespace noise
{

  namespace module
  {
    /// Default frequency for the noise::module::RidgedMulti noise module.
    const double DEFAULT_RIDGED_FREQUENCY = 1.0;

    /// Default lacunarity for the noise::module::RidgedMulti noise module.
    const double DEFAULT_RIDGED_LACUNARITY = 2.0;

    /// Default number of octaves for the noise::module::RidgedMulti noise
    const int DEFAULT_RIDGED_OCTAVE_COUNT = 6;

    /// Default noise quality for the noise::module::RidgedMulti noise
    const noise::NoiseQuality DEFAULT_RIDGED_QUALITY = QUALITY_STD;

    /// Default noise seed for the noise::module::RidgedMulti noise module.
    const int DEFAULT_RIDGED_SEED = 0;

    /// Maximum number of octaves for the noise::module::RidgedMulti noise
    /// module.
    const int RIDGED_MAX_OCTAVE = 30;

    
    /// This noise module, heavily based on the Perlin-noise module, generates
    /// ridged-multifractal noise.  Ridged-multifractal noise is generated in
    /// much of the same way as Perlin noise, except the output of each octave
    /// is modified by an absolute-value function.  Modifying the octave
    /// values in this way produces ridge-like formations.
    ///
    /// Ridged-multifractal noise does not use a persistence value.  This is
    /// because the persistence values of the octaves are based on the values
    /// generated from from previous octaves, creating a feedback loop (or
    /// that's what it looks like after reading the code.)
    ///
    /// This noise module outputs ridged-multifractal-noise values that
    /// usually range from -1.0 to +1.0, but there are no guarantees that all
    /// output values will exist within that range.
    ///
    /// @note For ridged-multifractal noise generated with only one octave,
    /// the output value ranges from -1.0 to 0.0.
    ///
    /// Ridged-multifractal noise is often used to generate craggy mountainous
    /// terrain or marble-like textures.
    
    /// The number of octaves control the <i>amount of detail</i> of the
    /// ridged-multifractal noise.  Adding more octaves increases the detail
    /// of the ridged-multifractal noise, but with the drawback of increasing
    /// the calculation time.
    ///
    /// An application may specify the number of octaves that generate
    /// ridged-multifractal noise by calling the SetOctaveCount() method.
    
    /// An application may specify the frequency of the first octave by
    /// calling the SetFrequency() method.
  
    /// The lacunarity specifies the frequency multipler between successive
    /// octaves.
    ///
    /// The effect of modifying the lacunarity is subtle; you may need to play
    /// with the lacunarity value to determine the effects.  For best results,
    /// set the lacunarity to a number between 1.5 and 3.5.
    ///
    
    class RidgedMulti: public Module
    {

      public:

        /// Constructor.
      
        RidgedMulti ();

        /// @returns The frequency of the first octave.
        double GetFrequency () const
        {
          return m_frequency;
        }

        /// @returns The lacunarity of the ridged-multifractal noise.
        /// 
        /// The lacunarity is the frequency multiplier between successive
        double GetLacunarity () const
        {
          return m_lacunarity;
        }

        /// @returns The quality of the ridged-multifractal noise.
      .
        noise::NoiseQuality GetNoiseQuality () const
        {
          return m_noiseQuality;
        }
        /// @returns The number of octaves that generate the
        /// ridged-multifractal noise.
        ///
        /// The number of octaves controls the amount of detail in the
        /// ridged-multifractal noise.
        int GetOctaveCount () const
        {
          return m_octaveCount;
        }

        /// @returns The seed value.
        int GetSeed () const
        {
          return m_seed;
        }

        virtual int GetSourceModuleCount () const
        {
          return 0;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// @param frequency The frequency of the first octave.
        void SetFrequency (double frequency)
        {
          m_frequency = frequency;
        }

        
        /// @param lacunarity The lacunarity of the ridged-multifractal noise.
        /// 
        /// The lacunarity is the frequency multiplier between successive
        void SetLacunarity (double lacunarity)
        {
          m_lacunarity = lacunarity;
          CalcSpectralWeights ();
        }

        /// @param noiseQuality The quality of the ridged-multifractal noise.
       
        void SetNoiseQuality (noise::NoiseQuality noiseQuality)
        {
          m_noiseQuality = noiseQuality;
        }

        /// @param octaveCount The number of octaves that generate the
        /// ridged-multifractal noise.
        ///
        /// @pre The number of octaves ranges from 1 to
        /// noise::module::RIDGED_MAX_OCTAVE.
        ///
        /// @throw noise::ExceptionInvalidParam An invalid parameter was
        /// specified; see the preconditions for more information.
        ///
        /// The number of octaves controls the amount of detail in the
        /// ridged-multifractal noise.
        ///
        /// The larger the number of octaves, the more time required to
        /// calculate the ridged-multifractal-noise value.
        void SetOctaveCount (int octaveCount)
        {
          if (octaveCount > RIDGED_MAX_OCTAVE) {
            throw noise::ExceptionInvalidParam ();
          }
          m_octaveCount = octaveCount;
        }

        /// @param seed The seed value.
        void SetSeed (int seed)
        {
          m_seed = seed;
        }

      protected:

        /// Calculates the spectral weights for each octave.
        void CalcSpectralWeights ();

        /// Frequency of the first octave.
        double m_frequency;

        /// Frequency multiplier between successive octaves.
        double m_lacunarity;

        /// Quality of the ridged-multifractal noise.
        noise::NoiseQuality m_noiseQuality;

        /// Total number of octaves that generate the ridged-multifractal
        /// noise.
        int m_octaveCount;

        /// Contains the spectral weights for each octave.
        double m_pSpectralWeights[RIDGED_MAX_OCTAVE];

        /// Seed value used by the ridged-multfractal-noise function.
        int m_seed;

    }

  }

}
