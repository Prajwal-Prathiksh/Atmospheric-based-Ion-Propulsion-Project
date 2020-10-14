/******************************************************************************/
/* 
    ion_transport.c - Source file
    ---------------------------------

    Reference:
    ----------
    https://www.afs.enea.it/project/neptunius/docs/fluent/html/udf/node90.htm

    Notes:
    ------
    Defines the advective flux term of `UDS1: RHO_Q` based on the Ion transport
    equation
*/
/******************************************************************************/

#include "udf.h"

DEFINE_UDS_FLUX(RHO_Q_flux, face, thread, i)
{
    real mu = 2.4e-4; // Value of ion mobility coefficient of air

    cell_t  c0,  c1 = -1;
    Thread *t0, *t1 = NULL;  

    real NV_VEC(psi_vec), NV_VEC(A), flux = 0.0;

    c0 = F_C0(face, thread);
    t0 = F_C0_THREAD(face, thread);
    F_AREA(A, face, thread);


    c1 = F_C1(face, thread);       // Get cell on other side of face
    t1 = F_C1_THREAD(face, thread); 

    psi_vec[0] = mu*C_UDSI_G(c0, t0, 0)[0] + C_U(c0, t0);
    psi_vec[0] += mu*C_UDSI_G(c1, t1, 0)[0] + C_U(c1, t1);

    psi_vec[1] = mu*C_UDSI_G(c0, t0, 0)[1] + C_V(c0, t0);
    psi_vec[1] += mu*C_UDSI_G(c1, t1, 0)[1] + C_V(c1, t1);

    flux = (psi_vec[0]*A[0] + psi_vec[1]*A[1])/2.0; /* Average flux through face */

    return flux;
}