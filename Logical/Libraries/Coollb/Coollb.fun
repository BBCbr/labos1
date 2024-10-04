
{REDUND_ERROR} FUNCTION_BLOCK FB_Motor (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR_OUTPUT
		w : {REDUND_UNREPLICABLE} REAL;
		phi : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		integrator : {REDUND_UNREPLICABLE} FB_Integrator;
		Tm : {REDUND_UNREPLICABLE} REAL;
		ke : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR_INPUT
		dt : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Integrator
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL;
		dt : REAL;
	END_VAR
	VAR_OUTPUT
		out : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		prev_value : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Controller
	VAR_INPUT
		e_in : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR_OUTPUT
		u_out : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		sum : REAL;
		a : REAL;
		k_p : REAL;
		k_i : REAL;
	END_VAR
	VAR_INPUT
		dt : REAL;
	END_VAR
	VAR
		max_abs_value : REAL;
		iyOld : REAL;
		integrator : FB_Integrator;
		last_sum : REAL;
	END_VAR
END_FUNCTION_BLOCK
