/* uds_names.h - Source file
   -------------------------

   Reference: 
      https://www.afs.enea.it/project/neptunius/docs/fluent/html/udf/node102.htm

   Notes:
      Renames the User Defined Scalars (UDS) to standard names
      * User Scalar 0 -> 'PHI' (Electric Potential; Units: V)
      * User Scalar 1 -> 'RHO_Q' (Charge Density; Units: C/m^3)
*/
#include "udf.h"
#include "sg_udms.h"

DEFINE_EXECUTE_ON_LOADING(Rename_UDS_Vars, libname)
{
    Set_User_Scalar_Name(0,"UDS0: PHI");
    Set_User_Scalar_Name(1, "UDS1: RHO_Q");
}