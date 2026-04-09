/*
 * asservissement.h
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

#include "motor.h"
#include "control.h"
#include "encoder.h"



typedef struct{
	float ref_speed;
	float Kp;
	float Ki;
	int32_t error_cumul;

} CONTROL;



void control_init(CONTROL * control,float Kp,float Ki);
void control_update(CONTROL * control, MOTOR *motor, ENCODER *encoder);
void control_set_speed(CONTROL * control, float ref_speed);
void error_reset(CONTROL* control);


#endif /* INC_CONTROL_H_ */
