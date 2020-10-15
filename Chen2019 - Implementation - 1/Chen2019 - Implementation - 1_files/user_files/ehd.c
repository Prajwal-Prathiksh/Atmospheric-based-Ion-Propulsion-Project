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

DEFINE_UDS_FLUX(RHO_Q_flux, f, t, i)
{
    cell_t c0;
    Thread *t0;

    real NV_VEC(A), psi_vec[2], flux = 0.0;

    c0 = F_C0(f, t);
    t0 = F_C0_THREAD(f,t);
    F_AREA(A, f, t);

    psi_vec[x] = -1.0 * mu * C_UDSI_G(c0,t0,PHI)[x] + C_U(c0,t0);
    psi_vec[y] = -1.0 * mu * C_UDSI_G(c0,t0,PHI)[y] + C_V(c0,t0);

    flux = psi_vec[x]*A[x] + psi_vec[y]*A[y];

    return flux;
}