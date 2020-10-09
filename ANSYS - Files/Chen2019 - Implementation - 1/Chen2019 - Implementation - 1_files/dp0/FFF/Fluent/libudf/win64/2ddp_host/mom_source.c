/*******************************************************************/
/* UDF for specifying momentum sources
*/
/*******************************************************************/

#include "udf.h"
#include "extfile.h"

#define C2 100.0

DEFINE_SOURCE(xmom_source, c, t, dS, eqn)
{
  real x[ND_ND];
  real con, source;

  C_CENTROID(x,c,t);
  con = C2*0.5*C_R(c,t)*x[1];

  source = -con*fabs( C_U(c, t) )*C_U(c,t);
  dS[eqn] = -2.*con*fabs(C_U(c,t));

  return source;
}

DEFINE_SOURCE(ymom_source, c, t, dS, eqn)
{
  real x[ND_ND];
  real con, source;

  C_CENTROID(x,c,t);
  con = C3*0.5*C_R(c,t)*x[0];

  source = -con*fabs( C_V(c, t) ) * C_V(c,t);
  dS[eqn] = -2.*con*fabs(C_V(c,t));

  return source;
}