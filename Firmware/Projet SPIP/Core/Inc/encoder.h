/*
 * encoder.h
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "main.h"

typedef struct encoder{
	TIM_HandleTypeDef * htim;
	int32_t compteur;
	int16_t derniere_valeur;
}ENCODER;

void encoder_init(ENCODER * encoder, TIM_HandleTypeDef * htim_param, int32_t compteur, int16_t derniere_valeur);
int16_t encoder_update(ENCODER * encoder);

#endif /* INC_ENCODER_H_ */
