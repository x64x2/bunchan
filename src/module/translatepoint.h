/*
 * translatepoint.h
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

#ifndef NOISE_MODULE_TRANSLATEPOINT_H
#define NOISE_MODULE_TRANSLATEPOINT_H
namespace noise
{

  namespace module
  {

    
    /// Default translation factor applied to the @a x coordinate for the
    /// noise::module::TranslatePoint noise module.
    const double DEFAULT_TRANSLATE_POINT_X = 0.0;

    /// Default translation factor applied to the @a y coordinate for the
    /// noise::module::TranslatePoint noise module.
    const double DEFAULT_TRANSLATE_POINT_Y = 0.0;

    /// Default translation factor applied to the @a z coordinate for the
    /// noise::module::TranslatePoint noise module.
    const double DEFAULT_TRANSLATE_POINT_Z = 0.0;

    /// Noise module that moves the coordinates of the input value before
    class TranslatePoint: public Module
    {

      public:

        /// Constructor.
        TranslatePoint ();

        virtual int GetSourceModuleCount () const
        {
          return 1;
        }

        virtual double GetValue (double x, double y, double z) const;

        /// @returns The translation amount to apply to the @a x coordinate.
        double GetXTranslation () const
        {
          return m_xTranslation;
        }
        /// @returns The translation amount to apply to the @a y coordinate.
        double GetYTranslation () const
        {
          return m_yTranslation;
        }

        /// @returns The translation amount to apply to the @a z coordinate.
        double GetZTranslation () const
        {
          return m_zTranslation;
        }

        /// @param translation The translation amount to apply.
       
        void SetTranslation (double translation)
        {
          m_xTranslation = translation;
          m_yTranslation = translation;
          m_zTranslation = translation;
        }

     
        /// @param xTranslation The translation amount to apply to the @a x
        /// coordinate.
        /// @param yTranslation The translation amount to apply to the @a y
        /// coordinate.
        /// @param zTranslation The translation amount to apply to the @a z
        
        void SetTranslation (double xTranslation, double yTranslation,
          double zTranslation)
        {
          m_xTranslation = xTranslation;
          m_yTranslation = yTranslation;
          m_zTranslation = zTranslation;
        }

       
        /// @param xTranslation The translation amount to apply to the @a x
        /// coordinate.
        void SetXTranslation (double xTranslation)
        {
          m_xTranslation = xTranslation;
        }

        /// @param yTranslation The translation amount to apply to the @a y coordinate.
        void SetYTranslation (double yTranslation)
        {
          m_yTranslation = yTranslation;
        }

        /// @param zTranslation The translation amount to apply to the @a 
        void SetZTranslation (double zTranslation)
        {
          m_zTranslation = zTranslation;
        }

      protected:

        /// Translation amount applied to the @a x coordinate of the input value.
        double m_xTranslation;

        /// Translation amount applied to the @a y coordinate of the input value.
        double m_yTranslation;

        /// Translation amount applied to the @a z coordinate of the input value.
        double m_zTranslation;

    }
  }

}

