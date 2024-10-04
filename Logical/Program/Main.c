
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	/*
	ke = 0.24
	Tm = 0.1
	
	k_p = 0.78
	k_i = 7.2
	
	наш двигун
	
	ke = 0.181
	Tm = 0.25
	
	k_p = 0.6525
	k_i = 2.0
	
	*/
	fb_motor1.ke = 0.24;
	fb_motor1.Tm = 0.1;
	fb_motor1.u = 0;
	
	fb_motor2.ke = 0.181;
	fb_motor2.Tm = 0.25;
	fb_motor2.u = 0;
	
	fb_controller.k_p = 0.78;
	fb_controller.k_i = 7.2;
	fb_controller.max_abs_value = 24.0;//24
	
	speed = 0;
	counter = 0;
	enable = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	if(enable)
	{
		if(counter == 200)
		{
			speed = 0;
			counter = 0;
		}
		else if (counter == 50)
		{
			speed = 50;
		}
		
		fb_controller.e_in = speed - fb_motor1.w;
		FB_Controller(&fb_controller);
		
		fb_motor1.u = fb_controller.u_out;
		FB_Motor(&fb_motor1);
		
		fb_motor2.u = speed * fb_motor2.ke;
		FB_Motor(&fb_motor2);
		
		counter++;
	}
	else
	{
		speed = 0;
		counter = 0;
	}
}

void _EXIT ProgramExit(void)
{

}

