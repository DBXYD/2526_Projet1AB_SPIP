/*
 * Ultrason.h
 *
 *  Created on: Apr 8, 2026
 *      Author: hugow
 */

#ifndef INC_ULTRASOUND_H_
#define INC_ULTRASOUND_H_

#include <stdint.h>
#include "stm32g4xx_hal.h"

typedef struct {
	TIM_HandleTypeDef* htim;
	GPIO_TypeDef* TRIG_Port;
	uint16_t      TRIG_Pin;
	GPIO_TypeDef* ECHO_Port;
	uint16_t      ECHO_Pin;
	volatile uint32_t echo_start;
	volatile uint32_t echo_end;
	float distance_cm;
} US_SENSOR;

void US_Init(US_SENSOR *us_sensor, TIM_HandleTypeDef *htim, GPIO_TypeDef* TRIG_Port,
             uint16_t TRIG_Pin, GPIO_TypeDef* ECHO_Port, uint16_t ECHO_Pin);

void US_Trigger(US_SENSOR* us_sensor);

void US_Update(US_SENSOR* us_sensor);



#endif /* INC_ULTRASOUND_H_ */
