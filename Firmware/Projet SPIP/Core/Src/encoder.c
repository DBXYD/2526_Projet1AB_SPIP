/*
 * encoder.c
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#include "encoder.h"

void encoder_init(ENCODER * encoder, TIM_HandleTypeDef * htim_param, int32_t compteur, int16_t derniere_valeur){
	encoder->htim =htim_param;
	encoder->compteur=0;
	encoder->derniere_valeur=0;
	HAL_TIM_Encoder_Start(htim_param, TIM_CHANNEL_ALL);
	encoder->htim->Instance->CNT=0;
}

int16_t encoder_update(ENCODER * encoder){
	uint16_t valeur_actuel=encoder->htim->Instance->CNT;
	int16_t difference=(int16_t)(valeur_actuel- encoder-> derniere_valeur);
	encoder->compteur+=difference;
	encoder->derniere_valeur=valeur_actuel;
	return difference;
}


