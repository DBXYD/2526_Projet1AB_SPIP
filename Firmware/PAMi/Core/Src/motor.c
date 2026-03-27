/*
 * motor.c
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#include "motor.h"

void motor_init(MOTOR * motor, TIM_HandleTypeDef * htim_param, uint32_t chA, uint32_t chB,uint32_t speed_max){
	motor->htim=htim_param;
	motor->ch_Forward=chA;
	motor->ch_Reverse=chB;
	motor->speed_final=0;
	motor->speed_max=speed_max;

    HAL_TIM_PWM_Start(motor->htim, motor->ch_Forward);
	HAL_TIM_PWM_Start(motor->htim, motor->ch_Reverse);

	motor_set_pwm(motor);
}

void motor_set_pwm(MOTOR * motor){
	int32_t speed = motor->speed_final;

	if (speed >= 0){
		if (speed > motor->speed_max){
			speed  = motor->speed_max;
		}
		__HAL_TIM_SET_COMPARE(motor->htim, motor->ch_Forward, speed );
		__HAL_TIM_SET_COMPARE(motor->htim, motor->ch_Reverse, 0);
	}
	else{
		if (speed < -motor->speed_max){
			speed=-motor->speed_max;
		}
		__HAL_TIM_SET_COMPARE(motor->htim, motor->ch_Forward, 0);
		__HAL_TIM_SET_COMPARE(motor->htim, motor->ch_Reverse, -speed);
	}
}

