/*
 * hacher.h
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#ifndef INC_HACHER_H_
#define INC_HACHER_H_

#include "encoder.h"
#include "motor.h"

typedef struct hacher{
	MOTOR motor;
	ENCODER encoder;
}HACHER;

void hacher_init(MOTOR * motor, TIM_HandleTypeDef * htim_param_motor, uint32_t chA, uint32_t chB, float speed, ENCODER * encoder,
		TIM_HandleTypeDef * htim_param_encoder, int32_t compteur, int16_t derniere_valeur);

#endif /* INC_HACHER_H_ */
