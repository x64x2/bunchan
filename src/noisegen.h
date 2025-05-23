/*
 * noisegen.h
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


#ifndef NOISE_NOISEGEN_H
#define NOISE_NOISEGEN_H

#include <math.h>
#include "basictypes.h"

namespace noise
{
  /// Enumerates the noise quality.
  enum NoiseQuality
  {

    /// Generates coherent noise quickly.  
    QUALITY_FAST = 0,

    /// Generates standard-quality coherent noise. 
    QUALITY_STD = 1,

    /// Generates the best-quality coherent noise.  
    QUALITY_BEST = 2

  };

  /// Generates a gradient-coherent-noise value from the coordinates of a
  /// three-dimensional input value.
  /// @param x The @a x coordinate of the input value.
  /// @param y The @a y coordinate of the input value.
  /// @param z The @a z coordinate of the input value.
  /// @param seed The random number seed.
  /// @param noiseQuality The quality of the coherent-noise.
  /// @returns The generated gradient-coherent-noise value.
  double GradientCoherentNoise3D (double x, double y, double z, int seed = 0,
    NoiseQuality noiseQuality = QUALITY_STD);

  /// Generates a gradient-noise value from the coordinates of a
  /// @param fx The floating-point @a x coordinate of the input value.
  /// @param fy The floating-point @a y coordinate of the input value.
  /// @param fz The floating-point @a z coordinate of the input value.
  /// @param ix The integer @a x coordinate of a nearby value.
  /// @param iy The integer @a y coordinate of a nearby value.
  /// @param iz The integer @a z coordinate of a nearby value.
  /// @param seed The random number seed.
  /// @returns The generated gradient-noise value.
  /// @pre The difference between @a fx and @a ix must be less than or equal
  /// to one.
  /// @pre The difference between @a fy and @a iy must be less than or equal
  /// to one.
  /// @pre The difference between @a fz and @a iz must be less than or equal
  /// to one.
  
  /// to it.
  double GradientNoise3D (double fx, double fy, double fz, int ix, int iy,
    int iz, int seed = 0);

  /// Generates an integer-noise value from the coordinates of a
  /// three-dimensional input value.
  /// @param x The integer @a x coordinate of the input value.
  /// @param y The integer @a y coordinate of the input value.
  /// @param z The integer @a z coordinate of the input value.
  /// @param seed A random number seed.
  /// @returns The generated integer-noise value
  int IntValueNoise3D (int x, int y, int z, int seed = 0);

  /// Modifies a floating-point value so that it can be stored in a
  noise::int32 variable.
  /// @param n A floating-point number.
  /// @returns The modified floating-point number.

  inline double MakeInt32Range (double n)
  {
    if (n >= 1073741824.0) {
      return (2.0 * fmod (n, 1073741824.0)) - 1073741824.0;
    } else if (n <= -1073741824.0) {
      return (2.0 * fmod (n, 1073741824.0)) + 1073741824.0;
    } else {
      return n;
    }
  }

  /// Generates a value-coherent-noise value from the coordinates of a
  /// three-dimensional input value.
  /// @param x The @a x coordinate of the input value.
  /// @param y The @a y coordinate of the input value.
  /// @param z The @a z coordinate of the input value.
  /// @param seed The random number seed.
  /// @param noiseQuality The quality of the coherent-noise.
  /// @returns The generated value-coherent-noise value.
  double ValueCoherentNoise3D (double x, double y, double z, int seed = 0,
    NoiseQuality noiseQuality = QUALITY_STD);

  /// Generates a value-noise value from the coordinates of a
  /// three-dimensional input value.
  /// @param x The @a x coordinate of the input value.
  /// @param y The @a y coordinate of the input value.
  /// @param z The @a z coordinate of the input value.
  /// @param seed A random number seed.
  /// @returns The generated value-noise value
  double ValueNoise3D (int x, int y, int z, int seed = 0);
}
