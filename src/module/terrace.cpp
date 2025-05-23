/*
 * terrace.cpp
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


#include "../interp.h"
#include "../misc.h"
#include "terrace.h"

using namespace noise::module;

using namespace noise;

Terrace::Terrace ():
  Module (GetSourceModuleCount ()),
  m_pControlPoints (NULL),
  m_controlPointCount (0),
  m_invertTerraces (false)
{
}

Terrace::~Terrace ()
{
  delete[] m_pControlPoints;
}

void Terrace::AddControlPoint (double value)
{
  /// Find the insertion point for the new control point and insert the new
  /// point at that position.  The control point array will remain sorted by
  int insertionPos = FindInsertionPos (value);
  InsertAtPos (insertionPos, value);
}

void Terrace::ClearAllControlPoints ()
{
  delete[] m_pControlPoints;
  m_pControlPoints = NULL;
  m_controlPointCount = 0;
}

int Terrace::FindInsertionPos (double value)
{
  int insertionPos;
  for (insertionPos = 0; insertionPos < m_controlPointCount; insertionPos++) {
    if (value < m_pControlPoints[insertionPos]) {
      /// found the array index in which to insert the new control point.
      break;
    } else if (value == m_pControlPoints[insertionPos]) {
      /// Each control point is required to contain a unique value, so throw
      throw noise::ExceptionInvalidParam ();
    }
  }
  return insertionPos;
}

double Terrace::GetValue (double x, double y, double z) const
{
  assert (m_pSourceModule[0] != NULL);
  assert (m_controlPointCount >= 2);

  /// Get the output value from the source module.
  double sourceModuleValue = m_pSourceModule[0]->GetValue (x, y, z);

  /// Find the first element in the control point array that has a value
  /// larger than the output value from the source module.
  int indexPos;
  for (indexPos = 0; indexPos < m_controlPointCount; indexPos++) {
    if (sourceModuleValue < m_pControlPoints[indexPos]) {
      break;
    }
  }

  /// Find the two nearest control points so that we can map their values
  /// onto a quadratic curve.
  int index0 = ClampValue (indexPos - 1, 0, m_controlPointCount - 1);
  int index1 = ClampValue (indexPos    , 0, m_controlPointCount - 1);

  /// If some control points are missing (which occurs if the output value from
  /// the source module is greater than the largest value or less than the
  if (index0 == index1) {
    return m_pControlPoints[index1];
  }
  
  /// Compute the alpha value used for linear interpolation.
  double value0 = m_pControlPoints[index0];
  double value1 = m_pControlPoints[index1];
  double alpha = (sourceModuleValue - value0) / (value1 - value0);
  if (m_invertTerraces) {
    alpha = 1.0 - alpha;
    SwapValues (value0, value1);
  }

  /// Squaring the alpha produces the terrace effect.
  alpha *= alpha;

  /// Now perform the linear interpolation given the alpha value.
  return LinearInterp (value0, value1, alpha);
}

void Terrace::InsertAtPos (int insertionPos, double value)
{
  /// Make room for the new control point at the specified position within
  double* newControlPoints = new double[m_controlPointCount + 1];
  for (int i = 0; i < m_controlPointCount; i++) {
    if (i < insertionPos) {
      newControlPoints[i] = m_pControlPoints[i];
    } else {
      newControlPoints[i + 1] = m_pControlPoints[i];
    }
  }
  delete[] m_pControlPoints;
  m_pControlPoints = newControlPoints;
  ++m_controlPointCount;

  /// Now that we've made room for the new control point within the array,
  /// add the new control point.
  m_pControlPoints[insertionPos] = value;
}

void Terrace::MakeControlPoints (int controlPointCount)
{
  if (controlPointCount < 2) {
    throw noise::ExceptionInvalidParam ();
  }

  ClearAllControlPoints ();

  double terraceStep = 2.0 / ((double)controlPointCount - 1.0);
  double curValue = -1.0;
  for (int i = 0; i < (int)controlPointCount; i++) {
    AddControlPoint (curValue);
    curValue += terraceStep;
  }
}
