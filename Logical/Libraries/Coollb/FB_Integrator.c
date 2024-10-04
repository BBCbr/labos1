
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Coollb.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Integrator(struct FB_Integrator* inst)
{
	inst->dt = 0.1;
	inst->out = inst->dt * inst->in + inst->prev_value;
	inst->prev_value = inst->out;
}
