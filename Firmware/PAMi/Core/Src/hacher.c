/*
 * hacher.c
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */
#include "hacher.h"

void hacher_init(MOTOR * motor, TIM_HandleTypeDef * htim_param_motor, uint32_t chA, uint32_t chB, float speed, ENCODER * encoder,
		TIM_HandleTypeDef * htim_param_encoder, int32_t compteur, int16_t derniere_valeur){

	motor_init(motor,htim_param_motor,chA,chB);
	encoder_init(encoder, htim_param_encoder,compteur,derniere_valeur);
}
