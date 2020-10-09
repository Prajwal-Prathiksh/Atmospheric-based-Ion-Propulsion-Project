/* This file generated automatically. */
/*          Do not modify.            */
#include "udf.h"
#include "prop.h"
#include "dpm.h"
extern DEFINE_PROFILE(inlet_x_velocity, thread, position);
extern DEFINE_SOURCE(xmom_source, c, t, dS, eqn);
extern DEFINE_SOURCE(ymom_source, c, t, dS, eqn);
__declspec(dllexport) UDF_Data udf_data[] = {
{"inlet_x_velocity", (void(*)())inlet_x_velocity, UDF_TYPE_PROFILE},
{"xmom_source", (void(*)())xmom_source, UDF_TYPE_SOURCE},
{"ymom_source", (void(*)())ymom_source, UDF_TYPE_SOURCE},
};
__declspec(dllexport) int n_udf_data = sizeof(udf_data)/sizeof(UDF_Data);
#include "version.h"
__declspec(dllexport) void UDF_Inquire_Release(int *major, int *minor, int *revision)
{
  *major = RampantReleaseMajor;
  *minor = RampantReleaseMinor;
  *revision = RampantReleaseRevision;
}
