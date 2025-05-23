/*
 * misc.h
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

#ifndef NOISE_MISC_H
#define NOISE_MISC_H

namespace noise
{

  /// Clamps a value onto a clamping range.
  ///
  /// @param value The value to clamp.
  /// @param lowerBound The lower bound of the clamping range.
  /// @param upperBound The upper bound of the clamping range.
  ///
  /// @returns
  /// - @a value if @a value lies between @a lowerBound and @a upperBound.
  /// - @a lowerBound if @a value is less than @a lowerBound.
  /// - @a upperBound if @a value is greater than @a upperBound.
  ///
  /// This function does not modify any parameters.
  inline int ClampValue (int value, int lowerBound, int upperBound)
  {
    if (value < lowerBound) {
      return lowerBound;
    } else if (value > upperBound) {
      return upperBound;
    } else {
      return value;
    }
  }
  /// @returns The maximum of the two values.
  template <class T>
  T GetMax (const T& a, const T& b)
  {
    return (a > b? a: b);
  }

  /// @returns The minimum of the two values.
  template <class T>
  T GetMin (const T& a, const T& b)
  {
    return (a < b? a: b);
  }
  
  /// @post The values within the the two variables are swapped.
  template <class T>
  void SwapValues (T& a, T& b)
  {
    T c = a;
    a = b;
    b = c;
  }

}
