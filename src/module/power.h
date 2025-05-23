


#include "modulebase.h"

#ifndef NOISE_MODULE_POWER_H
#define NOISE_MODULE_POWER_H

namespace noise
{

  namespace module
  {
    /// Noise module that raises the output value from a first source module
    /// to the power of the output value from a second source module.
 
    class Power: public Module
    {

      public:

        /// Constructor.
        Power ();

        virtual int GetSourceModuleCount () const
        {
          return 2;
        }

        virtual double GetValue (double x, double y, double z) const;

    }
  }

}


