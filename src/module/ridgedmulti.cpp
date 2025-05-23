/*
 * ridgedmulti.cpp
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


#include "ridgedmulti.h"

using namespace noise::module;

RidgedMulti::RidgedMulti ():
  Module (GetSourceModuleCount ()),
  m_octaveCount  (DEFAULT_RIDGED_OCTAVE_COUNT),
  m_frequency    (DEFAULT_RIDGED_FREQUENCY   ),
  m_lacunarity   (DEFAULT_RIDGED_LACUNARITY  ),
  m_noiseQuality (DEFAULT_RIDGED_QUALITY     ),
  m_seed         (DEFAULT_RIDGED_SEED)
{
  CalcSpectralWeights ();
}

/// Calculates the spectral weights for each octave.
void RidgedMulti::CalcSpectralWeights ()
{
  /// This exponent parameter should be user-defined; it may be exposed in a
  /// future version of libnoise.
  double h = 1.0;

  double frequency = 1.0;
  for (int i = 0; i < RIDGED_MAX_OCTAVE; i++) {
    // Compute weight for each frequency.
    m_pSpectralWeights[i] = pow (frequency, -h);
    frequency *= m_lacunarity;
  }
}

/// Multifractal code originally written by F. Kenton "Doc Mojo" Musgrave
double RidgedMulti::GetValue (double x, double y, double z) const
{
  x *= m_frequency;
  y *= m_frequency;
  z *= m_frequency;

  double signal = 0.0;
  double value  = 0.0;
  double weight = 1.0;

  // These parameters should be user-defined; they may be exposed in a
  // future version of libnoise.
  double offset = 1.0;
  double gain = 2.0;

  for (int curOctave = 0; curOctave < m_octaveCount; curOctave++) {

    // Make sure that these floating-point values have the same range as a 32-
    // bit integer so that we can pass them to the coherent-noise functions.
    double nx, ny, nz;
    nx = MakeInt32Range (x);
    ny = MakeInt32Range (y);
    nz = MakeInt32Range (z);

    /// Get the coherent-noise value.
    int seed = (m_seed + curOctave) & 0x7fffffff;
    signal = GradientCoherentNoise3D (nx, ny, nz, seed, m_noiseQuality);

    /// Make the ridges.
    signal = fabs (signal);
    signal = offset - signal;

    /// Square the signal to increase the sharpness of the ridges.
    signal *= signal;

    /// The weighting from the previous octave is applied to the signal.
    /// Larger values have higher weights, producing sharp points along the
    /// ridges.
    signal *= weight;

    /// Weight successive contributions by the previous signal.
    weight = signal * gain;
    if (weight > 1.0) {
      weight = 1.0;
    }
    if (weight < 0.0) {
      weight = 0.0;
    }

    /// Add the signal to the output value.
    value += (signal * m_pSpectralWeights[curOctave]);

    /// Go to the next octave.
    x *= m_lacunarity;
    y *= m_lacunarity;
    z *= m_lacunarity;
  }

  return (value * 1.25) - 1.0;
}
