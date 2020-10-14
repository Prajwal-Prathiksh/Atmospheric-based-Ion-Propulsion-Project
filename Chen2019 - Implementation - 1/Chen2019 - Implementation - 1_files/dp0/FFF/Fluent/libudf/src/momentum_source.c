/******************************************************************************/
/*
   momentum_source.c - Source file
   -------------------------------

   Reference: 
   ----------
   https://www.afs.enea.it/project/neptunius/docs/fluent/html/udf/node49.htm
   https://www.afs.enea.it/project/neptunius/docs/fluent/html/udf/node102.htm


   Notes:
   ------
    Defines the source terms for the Momentum equation:
        * X - Momentum
        * Y - Momentum
        * Z - Momentum
*/
/******************************************************************************/

#include "udf.h"

DEFINE_SOURCE(X_MOM_source, cell, thread, dS, eqn)
{
    real source; // Define source variable

    // Initialise source value 
    source = C_UDSI(cell, thread, 1) * -1.0 * C_UDSI_G(cell, thread, 0)[0];

    dS[eqn] = 0.0;
    
    return source;
}

DEFINE_SOURCE(Y_MOM_source, cell, thread, dS, eqn)
{
    real source; // Define source variable

    // Initialise source value 
    source = C_UDSI(cell, thread, 1) * -1.0 * C_UDSI_G(cell, thread, 0)[1];

    dS[eqn] = 0.0;
    
    return source;
}

DEFINE_SOURCE(Z_MOM_source, cell, thread, dS, eqn)
{
    real source; // Define source variable

    // Initialise source value 
    source = C_UDSI(cell, thread, 1) * -1.0 * C_UDSI_G(cell, thread, 0)[2];

    dS[eqn] = 0.0;
    
    return source;
}