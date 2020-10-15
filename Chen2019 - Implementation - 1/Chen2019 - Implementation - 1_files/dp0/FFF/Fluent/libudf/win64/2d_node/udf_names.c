/* This file generated automatically. */
/*          Do not modify.            */
#include "udf.h"
#include "prop.h"
#include "dpm.h"
extern DEFINE_EXECUTE_ON_LOADING(UDS_Vars, libname);
extern DEFINE_ON_DEMAND(Rename_UDS_Vars);
extern DEFINE_ADJUST(Compute_Electric_Field, domain);
extern DEFINE_SOURCE(PHI_source, c, t, dS, eqn);
extern DEFINE_SOURCE(x_mom_source, c, t, dS, eqn);
extern DEFINE_SOURCE(y_mom_source, c, t, dS, eqn);
extern DEFINE_UDS_FLUX(RHO_Q_flux, f, t, i);
__declspec(dllexport) UDF_Data udf_data[] = {
{"UDS_Vars", (void(*)())UDS_Vars, UDF_TYPE_EXECUTE_ON_LOADING},
{"Rename_UDS_Vars", (void(*)())Rename_UDS_Vars, UDF_TYPE_ON_DEMAND},
{"Compute_Electric_Field", (void(*)())Compute_Electric_Field, UDF_TYPE_ADJUST},
{"PHI_source", (void(*)())PHI_source, UDF_TYPE_SOURCE},
{"x_mom_source", (void(*)())x_mom_source, UDF_TYPE_SOURCE},
{"y_mom_source", (void(*)())y_mom_source, UDF_TYPE_SOURCE},
{"RHO_Q_flux", (void(*)())RHO_Q_flux, UDF_TYPE_UDS_FLUX},
};
__declspec(dllexport) int n_udf_data = sizeof(udf_data)/sizeof(UDF_Data);
#include "version.h"
__declspec(dllexport) void UDF_Inquire_Release(int *major, int *minor, int *revision)
{
  *major = RampantReleaseMajor;
  *minor = RampantReleaseMinor;
  *revision = RampantReleaseRevision;
}
