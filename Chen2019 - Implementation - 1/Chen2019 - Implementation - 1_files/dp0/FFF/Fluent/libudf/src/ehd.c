#include "udf.h"
#include "mem.h"
#include "sg_udms.h"

#define PHI 0
#define RHO_Q 1

#define Ex 0
#define Ey 1
#define Emag 2

#define x 0
#define y 1

// Value of ion mobility coefficient of air
#define mu 2.4e-4 
#define eps_o 8.854e-12

DEFINE_EXECUTE_ON_LOADING(UDS_Vars, libname)
{
    Set_User_Scalar_Name(PHI, "PHI");
    Set_User_Scalar_Name(RHO_Q, "RHO_Q");

    Set_User_Memory_Name(Ex, "E-x");
    Set_User_Memory_Name(Ey, "E-y");
    Set_User_Memory_Name(Emag, "E-mag");
}

DEFINE_ON_DEMAND(Rename_UDS_Vars)
{
    Set_User_Scalar_Name(PHI, "PHI");
    Set_User_Scalar_Name(RHO_Q, "RHO_Q");

    Set_User_Memory_Name(Ex, "E-x");
    Set_User_Memory_Name(Ey, "E-y");
    Set_User_Memory_Name(Emag, "E-mag");
}

DEFINE_ADJUST(Compute_Electric_Field, domain)  
{
    Thread *t;
    cell_t c;
  
    thread_loop_c (t, domain)
    {
        Thread *t_gas = THREAD_SUB_THREAD(t, 0);
        begin_c_loop (c, t)
            {
                // Ex = - grad(PHI) x-component
                C_UDMI(c, t, Ex) = -1.0 * C_UDSI_G(c, t, PHI)[x]; 
                
                // Ey = - grad(PHI) y-component
                C_UDMI(c, t, Ey) = -1.0 * C_UDSI_G(c, t, PHI)[y]; 

                // E-mag = sqrt(grad(PHI))
                C_UDMI(c, t, Emag) = sqrt( C_UDSI_G(c, t, PHI)[x] * C_UDSI_G(c, t, PHI)[x] + C_UDSI_G(c, t, PHI)[y] * C_UDSI_G(c, t, PHI)[y] ); 
            }
        end_c_loop(c, t)
    }
}

DEFINE_SOURCE(PHI_source, c, t, dS, eqn)
{
    real source; // Define source variable
    
    // Initialise source value with RHO_Q
    source = C_UDSI(c, t, RHO_Q);

    dS[eqn] = 0.0;
    
    return source;
}

DEFINE_SOURCE(x_mom_source, c, t, dS, eqn)
{
    real source; // Define source variable

    // Initialise source value 
    source = C_UDSI(c, t, RHO_Q) * -1.0 * C_UDSI_G(c, t, PHI)[x];

    dS[eqn] = 0.0;
    
    return source;
}

DEFINE_SOURCE(y_mom_source, c, t, dS, eqn)
{
    real source; // Define source variable

    // Initialise source value 
    source = C_UDSI(c, t, RHO_Q) * -1.0 * C_UDSI_G(c, t, PHI)[y];

    dS[eqn] = 0.0;
    
    return source;
}


DEFINE_SOURCE(RHO_Q_source, c, t, dS, eqn)
{
    real source, gradrho_dot_gradphi; // Define source variable

    // Initialise source value 

    gradrho_dot_gradphi = C_UDSI_G(c, t, RHO_Q)[x]*C_UDSI_G(c, t, PHI)[x] + C_UDSI_G(c, t, RHO_Q)[y]*C_UDSI_G(c, t, PHI)[y];
    source = gradrho_dot_gradphi + C_UDSI(c, t, RHO_Q)*C_UDSI(c, t, RHO_Q)/eps_o;

    dS[eqn] = 0.0;
    
    return source;
}


DEFINE_UDS_FLUX(RHO_Q_flux,f,t,i)
{
  cell_t  c0,  c1 = -1;
  Thread *t0, *t1 = NULL;

  real NV_VEC(psi_vec), NV_VEC(A), flux = 0.0, temp1, temp2;

  c0 = F_C0(f,t);
  t0 = F_C0_THREAD(f,t);
  F_AREA(A, f, t);

  temp1 = -1.0 * mu * C_UDSI_G(c0,t0,PHI)[x];
  temp2 = -1.0 * mu * C_UDSI_G(c0,t0,PHI)[y];

  /* If face lies at domain boundary, use face values; */
  /* If face lies IN the domain, use average of adjacent cells. */

 if (BOUNDARY_FACE_THREAD_P(t)) /*Most face values will be available*/
    {

      //NV_DS(psi_vec,  =, temp1+F_U(f,t), temp2+F_V(f,t), F_W(f,t), *, 1.0);
      NV_DS(psi_vec,  =, temp1, temp2, F_W(f,t), *, 1.0);

      flux = NV_DOT(psi_vec, A); /* flux through Face */
    }
  else
    {
      c1 = F_C1(f,t);       /* Get cell on other side of face */
      t1 = F_C1_THREAD(f,t); 

      //NV_DS(psi_vec,  =, temp1+C_U(c0,t0),temp2+C_V(c0,t0),C_W(c0,t0),*,1.0);
      //NV_DS(psi_vec,  =, temp1,temp2,C_W(c0,t0),*,1.0);

      temp1 = -1.0 * mu * C_UDSI_G(c1,t1,PHI)[x];
      temp2 = -1.0 * mu * C_UDSI_G(c1,t1,PHI)[y];
      //NV_DS(psi_vec, +=, temp1+C_U(c1,t1),temp2+C_V(c1,t1),C_W(c1,t1),*,1.0);
      NV_DS(psi_vec, +=, temp1,temp2,C_W(c1,t1),*,1.0);

      flux = NV_DOT(psi_vec, A)/2.0; /* Average flux through face */
    }

  return flux;
}