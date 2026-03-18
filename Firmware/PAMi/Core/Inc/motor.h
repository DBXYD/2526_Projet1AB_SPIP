/*
 * motor.h
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"

typedef struct motor{
	TIM_HandleTypeDef * htim;
	uint32_t channel_A;
	uint32_t channel_B;
	float speed;
	float erreur_accumulee;
	uint32_t ARR;
}MOTOR;

void motor_init(MOTOR * motor, TIM_HandleTypeDef * htim_param, uint32_t chA, uint32_t chB);
void motor_apply(MOTOR * motor);

#endif /* INC_MOTOR_H_ */
