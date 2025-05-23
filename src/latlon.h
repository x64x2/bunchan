/*
 * latlon.h
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


#include <math.h>
#include "mathconsts.h"


#ifndef NOISE_LATLON_H
#define NOISE_LATLON_H

namespace noise
{

  /// @addtogroup libnoise
  /// Converts latitude/longitude coordinates on a unit sphere into 3D
  /// Cartesian coordinates.
  /// @param lat The latitude, in degrees.
  /// @param lon The longitude, in degrees.
  /// @param x On exit, this parameter contains the @a x coordinate.
  /// @param y On exit, this parameter contains the @a y coordinate.
  /// @param z On exit, this parameter contains the @a z coordinate.
  /// @pre lat must range from @b -90 to @b +90.
  /// @pre lon must range from @b -180 to @b +180.
  void LatLonToXYZ (double lat, double lon, double& x, double& y, double& z);
}
