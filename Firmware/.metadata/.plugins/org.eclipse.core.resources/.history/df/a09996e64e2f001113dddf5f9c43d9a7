/*
 * asservissement.c
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#include "asservissement.h"

void asser_init(ASSERVISSEMENT * asser,float Kp,float Ki){
	asser->ref_speed=0;
	asser->Kp=Kp;
	asser->Ki=Ki;
	asser->error_cumul=0;
}
void asser_set_speed(ASSERVISSEMENT * asser,float ref_speed) {
	asser->ref_speed = ref_speed;
}

void asser_update(ASSERVISSEMENT *asser, MOTOR *motor,ENCODER *encoder) {
	int32_t error=asser->ref_speed - 1000*encoder->delta_ticks;
	asser->error_cumul  += error;
	motor->speed_final = (asser->Kp * error) + (asser->Ki * asser->error_cumul);

	motor_set_pwm(motor);
}
