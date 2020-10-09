/***********************************************************************
vprofile.c
UDF for specifying steady-state velocity profile boundary condition
************************************************************************/

#include "udf.h"

DEFINE_PROFILE(inlet_x_velocity, thread, position)
{
  real x[ND_ND]; /* this will hold the position vector */
  real y, vel, h;
  face_t f;

  vel = 10.0; 
  h = 200e-4;

  begin_f_loop(f, thread)
  {
    F_CENTROID(x, f, thread);
    y = x[1]; /* non-dimensional y coordinate */
    F_PROFILE(f, thread, position) = fabs( vel * cos(2.0*M_PI*(y/h)) );
  }
  end_f_loop(f, thread)

}