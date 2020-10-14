/* This file generated automatically. */
/*          Do not modify.            */
#include "udf.h"
#include "prop.h"
#include "dpm.h"
extern DEFINE_UDS_FLUX(RHO_Q_flux, face, thread, i);
extern DEFINE_SOURCE(X_MOM_source, cell, thread, dS, eqn);
extern DEFINE_SOURCE(Y_MOM_source, cell, thread, dS, eqn);
extern DEFINE_SOURCE(Z_MOM_source, cell, thread, dS, eqn);
extern DEFINE_SOURCE(PHI_source, cell, thread, dS, eqn);
extern DEFINE_EXECUTE_ON_LOADING(Rename_UDS_Vars, libname);
__declspec(dllexport) UDF_Data udf_data[] = {
{"RHO_Q_flux", (void(*)())RHO_Q_flux, UDF_TYPE_UDS_FLUX},
{"X_MOM_source", (void(*)())X_MOM_source, UDF_TYPE_SOURCE},
{"Y_MOM_source", (void(*)())Y_MOM_source, UDF_TYPE_SOURCE},
{"Z_MOM_source", (void(*)())Z_MOM_source, UDF_TYPE_SOURCE},
{"PHI_source", (void(*)())PHI_source, UDF_TYPE_SOURCE},
{"Rename_UDS_Vars", (void(*)())Rename_UDS_Vars, UDF_TYPE_EXECUTE_ON_LOADING},
};
__declspec(dllexport) int n_udf_data = sizeof(udf_data)/sizeof(UDF_Data);
#include "version.h"
__declspec(dllexport) void UDF_Inquire_Release(int *major, int *minor, int *revision)
{
  *major = RampantReleaseMajor;
  *minor = RampantReleaseMinor;
  *revision = RampantReleaseRevision;
}
