/******************************************************************************/
/* 
    poisson_equation.c - Source file
    ---------------------------------

    Reference:
    ----------
    https://www.afs.enea.it/project/neptunius/docs/fluent/html/udf/node49.htm
    https://www.afs.enea.it/project/neptunius/docs/fluent/html/udf/node102.htm

    Notes:
    ------
    Defines the Source of `UDS0: PHI` based on the Poisson's equation
*/
/******************************************************************************/

#include "udf.h"

DEFINE_SOURCE(PHI_source, cell, thread, dS, eqn)
{
    real source; // Define source variable
    source = C_UDSI(cell, thread, 1); // Initialise source value with `UDS1: RHO_Q`

    dS[eqn] = 0.0;
    
    return source;
}