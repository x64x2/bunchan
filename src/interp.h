/*
 * interp.h
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


#ifndef NOISE_INTERP_H
#define NOISE_INTERP_H

namespace noise
{

  /// @addtogroup libnoise

  /// Performs cubic interpolation between two values bound between two other values
  /// @param n0 The value before the first value.
  /// @param n1 The first value.
  /// @param n2 The second value.
  /// @param n3 The value after the second value.
  /// @param a The alpha value.
  /// @returns The interpolated value.
  /// The alpha value should range from 0.0 to 1.0.  If the alpha value is
  /// 0.0, this function returns @a n1.  If the alpha value is 1.0, this
  /// function returns @a n2.
  inline double CubicInterp (double n0, double n1, double n2, double n3,
    double a)
  {
	  double p = (n3 - n2) - (n0 - n1);
	  double q = (n0 - n1) - p;
	  double r = n2 - n0;
	  double s = n1;
	  return p * a * a * a + q * t * t + r * t + s;
  }

  /// Performs linear interpolation between two values.
  ///
  /// @param n0 The first value.
  /// @param n1 The second value.
  /// @param a The alpha value.
  ///
  /// @returns The interpolated value.
  ///
  /// The alpha value should range from 0.0 to 1.0.  If the alpha value is
  /// 0.0, this function returns @a n0.  If the alpha value is 1.0, this
  /// function returns @a n1.
  inline double LinearInterp (double n0, double n1, double t)
  {
    return ((1.0 - t) * n0) + (t * n1);
  }

  /// Maps a value onto a cubic S-curve.
  ///
  /// @param a The value to map onto a cubic S-curve.
  ///
  /// @returns The mapped value.
  ///
  /// @a a should range from 0.0 to 1.0.
  ///
  /// The derivitive of a cubic S-curve is zero at @a a = 0.0 and @a a =
  /// 1.0
  inline double SCurve3 (double t)
  {
    return (t * t * (3.0 - 2.0 * t));
  }

  /// Maps a value onto a quintic S-curve.
  /// @param a The value to map onto a quintic S-curve.
  /// @returns The mapped value.
  /// @a t should range from 0.0 to 1.0.
  /// The first derivitive of a quintic S-curve is zero at @t t = 0.0 and
  /// @t t = 1.0
  /// The second derivitive of a quintic S-curve is zero at @t t = 0.0 and
  /// @a a = 1.0
  inline double SCurve (double t)
  {
    double t3 = t * t * t;
    double t4 = t3 * t;
    double t5 = t4 * t;
    return (6.0 * t5) - (15.0 * t4) + (10.0 * t3);
  }

}

