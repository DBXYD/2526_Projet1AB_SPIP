/*
 * asservissement.c
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#include <control.h>

void control_init(CONTROL * control,float Kp,float Ki){
	control->ref_speed=0;
	control->Kp=Kp;
	control->Ki=Ki;
	control->error_cumul=0;
}
void control_set_speed(CONTROL * control,float ref_speed) {
	control->ref_speed = ref_speed;
}

void control_update(CONTROL *control, MOTOR *motor,ENCODER *encoder) {
	int32_t error= control ->ref_speed - 1000*encoder->delta_ticks;
	control->error_cumul  += error;
	motor->speed_final = control->ref_speed +(control->Kp * error) + (control->Ki * control->error_cumul);

	motor_set_pwm(motor);
}

void error_reset(CONTROL* control){
	control->error_cumul = 0;
}
