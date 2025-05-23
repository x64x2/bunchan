/*
 * perlin.h
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

#ifndef NOISE_MODULE_PERLIN_H
#define NOISE_MODULE_PERLIN_H
namespace noise
{

  namespace module
  {
    /// Default frequency for the noise::module::Perlin noise module.
    const double DEFAULT_PERLIN_FREQUENCY = 1.0;

    /// Default lacunarity for the noise::module::Perlin noise module.
    const double DEFAULT_PERLIN_LACUNARITY = 2.0;

    /// Default number of octaves for the noise::module::Perlin noise module.
    const int DEFAULT_PERLIN_OCTAVE_COUNT = 6;

    /// Default persistence value for the noise::module::Perlin noise module.
    const double DEFAULT_PERLIN_PERSISTENCE = 0.5;

    /// Default noise quality for the noise::module::Perlin noise module.
    const noise::NoiseQuality DEFAULT_PERLIN_QUALITY = QUALITY_STD;

    /// Default noise seed for the noise::module::Perlin noise module.
    const int DEFAULT_PERLIN_SEED = 0;

    /// Maximum number of octaves for the noise::module::Perlin noise module.
    const int PERLIN_MAX_OCTAVE = 30;

    /// Noise module that outputs 3-dimensional Perlin noise.
  
    /// Perlin noise is the sum of several coherent-noise functions of
    /// ever-increasing frequencies and ever-decreasing amplitudes.
    ///
    /// An important property of Perlin noise is that a small change in the
    /// input value will produce a small change in the output value, while a
    /// large change in the input value will produce a random change in the
    /// output value.
    ///
    /// This noise module outputs Perlin-noise values that usually range from
    /// -1.0 to +1.0, but there are no guarantees that all output values will
    
    /// The number of octaves control the <i>amount of detail</i> of the
    /// Perlin noise.  Adding more octaves increases the detail of the Perlin
    /// noise, but with the drawback of increasing the calculation time.
    ///
    /// An octave is one of the coherent-noise functions in a series of
    /// coherent-noise functions that are added together to form Perlin
    /// noise.
    ///
    /// An application may specify the frequency of the first octave by
    /// calling the SetFrequency() method.
    ///
    /// An application may specify the number of octaves that generate Perlin
    /// noise by calling the SetOctaveCount() method.
    ///
    /// These coherent-noise functions are called octaves because each octave
    /// has, by default, double the frequency of the previous octave.  Musical
    /// tones have this property as well; a musical C tone that is one octave
    /// higher than the previous C tone has double its frequency.
    
    /// An application may specify the frequency of the first octave by
    /// calling the SetFrequency() method.
   
    /// The persistence value controls the roughness of the Perlin
    /// noise.  Larger values produce rougher noise.
    ///
    /// The persistence value determines how quickly the amplitudes diminish
    /// for successive octaves.  The amplitude of the first octave is 1.0.
    /// The amplitude of each subsequent octave is equal to the product of the
    /// previous octave's amplitude and the persistence value.  So a
    /// persistence value of 0.5 sets the amplitude of the first octave to
    /// 1.0; the second, 0.5; the third, 0.25; etc.
    ///
    /// An application may specify the persistence value by calling the
    /// SetPersistence() method.
   
    /// The lacunarity specifies the frequency multipler between successive
    /// octaves.
    ///
    /// The effect of modifying the lacunarity is subtle; you may need to play
    /// with the lacunarity value to determine the effects.  For best results,
    /// set the lacunarity to a number between 1.5 and 3.5.
    ///
   
    class Perlin: public Module
    {

      public:

        /// Constructor.
        ///
        /// The default frequency is set to
        /// noise::module::DEFAULT_PERLIN_FREQUENCY.
        ///
        /// The default lacunarity is set to
        /// noise::module::DEFAULT_PERLIN_LACUNARITY.
        ///
        /// The default number of octaves is set to
        /// noise::module::DEFAULT_PERLIN_OCTAVE_COUNT.
        ///
        /// The default persistence value is set to
        /// noise::module::DEFAULT_PERLIN_PERSISTENCE.
        ///
        /// The default seed value is set to
        /// noise::module::DEFAULT_PERLIN_SEED.
        Perlin ();

        /// Returns the frequency of the first octave.
        ///
        /// @returns The frequency of the first octave.
        double GetFrequency () const
        {
          return m_frequency;
        }

        
        /// @returns The lacunarity of the Perlin noise.
        /// 
        /// The lacunarity is the frequency multiplier between successive
        /// octaves.
        double GetLacunarity () const
        {
          return m_lacunarity;
        }

        /// @returns The quality of the Perlin noise.
        ///
        /// See noise::NoiseQuality for definitions of the various
        /// coherent-noise qualities.
        noise::NoiseQuality GetNoiseQuality () const
        {
          return m_noiseQuality;
        }

        /// @returns The number of octaves that generate the Perlin noise.
      
        int GetOctaveCount () const
        {
          return m_octaveCount;
        }

       
        /// @returns The persistence value of the Perlin noise.
        ///
        /// The persistence value controls the roughness of the Perlin noise.
        double GetPersistence () const
        {
          return m_persistence;
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

        /// @param lacunarity The lacunarity of the Perlin noise.
        
        void SetLacunarity (double lacunarity)
        {
          m_lacunarity = lacunarity;
        }

       
        /// @param noiseQuality The quality of the Perlin noise.
       
        void SetNoiseQuality (noise::NoiseQuality noiseQuality)
        {
          m_noiseQuality = noiseQuality;
        }

     
        /// @param octaveCount The number of octaves that generate the Perlin
        /// noise.
        ///
        /// @pre The number of octaves ranges from 1 to
        /// noise::module::PERLIN_MAX_OCTAVE.
        ///
        /// @throw noise::ExceptionInvalidParam An invalid parameter was
        /// specified; see the preconditions for more information.
        ///
        /// The number of octaves controls the amount of detail in the Perlin
        /// noise.
        ///
        /// The larger the number of octaves, the more time required to
        /// calculate the Perlin-noise value.
        void SetOctaveCount (int octaveCount)
        {
          if (octaveCount < 1 || octaveCount > PERLIN_MAX_OCTAVE) {
            throw noise::ExceptionInvalidParam ();
          }
          m_octaveCount = octaveCount;
        }

        
        /// @param persistence The persistence value of the Perlin noise.
        
        void SetPersistence (double persistence)
        {
          m_persistence = persistence;
        }

        /// @param seed The seed value.
        void SetSeed (int seed)
        {
          m_seed = seed;
        }

      protected:

        /// Frequency of the first octave.
        double m_frequency;

        /// Frequency multiplier between successive octaves.
        double m_lacunarity;

        /// Quality of the Perlin noise.
        noise::NoiseQuality m_noiseQuality;

        /// Total number of octaves that generate the Perlin noise.
        int m_octaveCount;

        /// Persistence of the Perlin noise.
        double m_persistence;

        /// Seed value used by the Perlin-noise function.
        int m_seed;

    }
  }

}
