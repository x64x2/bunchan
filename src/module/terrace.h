/*
 * terrace.h
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

#ifndef NOISE_MODULE_TERRACE_H
#define NOISE_MODULE_TERRACE_H

namespace noise
{

  namespace module
  {

    /// Noise module that maps the output value from a source module onto a
    /// terrace-forming curve.
   
    class Terrace: public Module
    {

	    public:

	      /// Constructor.
	      Terrace ();

	      /// Destructor.
	      ~Terrace ();

	      /// @param value The value of the control point to add.
	      ///
	      /// @pre No two control points have the same value.
	      ///
	      /// @throw noise::ExceptionInvalidParam An invalid parameter was
        /// specified; see the preconditions for more information.
	      ///
	      /// Two or more control points define the terrace-forming curve. 
	      void AddControlPoint (double value);

	      /// Deletes all the control points on the terrace-forming curve.
	      ///
	      /// @post All control points on the terrace-forming curve are deleted.
	      void ClearAllControlPoints ();

	      /// @returns A pointer to the array of control points in this noise
	
	      const double* GetControlPointArray () const
	      {
	        return m_pControlPoints;
	      }

	      /// @returns The number of control points on the terrace-forming
	      int GetControlPointCount () const
	      {
	        return m_controlPointCount;
	      }

    	  virtual int GetSourceModuleCount () const
	      {
	        return 1;
	      }
	      /// @param invert Specifies whether to invert the curve between the
    
	      void InvertTerraces (bool invert = true)
	      {
	        m_invertTerraces = invert;
	      }

        /// @returns
        /// - @a true if the curve between the control points is inverted.
        /// - @a false if the curve between the control points is not
        
        bool IsTerracesInverted () const
        {
	        return m_invertTerraces;
        }

    	  virtual double GetValue (double x, double y, double z) const;

	      /// @param controlPointCount The number of control points to generate.
	      ///
	      /// @pre The number of control points must be greater than or equal to
	      /// 2.
	      ///
	      /// @post The previous control points on the terrace-forming curve are
        /// deleted.
	      ///
	      /// @throw noise::ExceptionInvalidParam An invalid parameter was
        /// specified; see the preconditions for more information.
	   
        void MakeControlPoints (int controlPointCount);

    	protected:

	      /// @param value The value of the control point.
	      ///
	      /// @returns The array index in which to insert the control point.
	      ///
	      /// @pre No two control points have the same value.
	      ///
	      /// @throw noise::ExceptionInvalidParam An invalid parameter was
        /// specified; see the preconditions for more information.
	     
	      int FindInsertionPos (double value);

	      /// @param insertionPos The zero-based array position in which to
        /// insert the control point.
	      /// @param value The value of the control point.
	   .
	      void InsertAtPos (int insertionPos, double value);

	      /// Number of control points stored in this noise module.
	      int m_controlPointCount;

        /// Determines if the terrace-forming curve between all control points
        /// is inverted.
	      bool m_invertTerraces;

	      /// Array that stores the control points.
	      double* m_pControlPoints;

    }
  }

}


