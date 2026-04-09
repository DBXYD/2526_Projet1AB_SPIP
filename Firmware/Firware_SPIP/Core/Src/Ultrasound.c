/*
 * Ultrason.c
 *
 *  Created on: Apr 8, 2026
 *      Author: hugow
 */

#include <Ultrasound.h>

void US_Init(US_SENSOR *us_sensor, TIM_HandleTypeDef *htim, GPIO_TypeDef* TRIG_Port,
		uint16_t TRIG_Pin, GPIO_TypeDef* ECHO_Port, uint16_t ECHO_Pin) {
    us_sensor->htim = htim;
    us_sensor->TRIG_Port = TRIG_Port;
    us_sensor->TRIG_Pin = TRIG_Pin;
    us_sensor->ECHO_Port = ECHO_Port;
    us_sensor->ECHO_Pin = ECHO_Pin;
    us_sensor->echo_start = 0;
    us_sensor->echo_end = 0;
    us_sensor->distance_cm = 0.0;
}

void US_Trigger(US_SENSOR* us_sensor) {
    HAL_GPIO_WritePin(us_sensor->TRIG_Port, us_sensor->TRIG_Pin, GPIO_PIN_SET);
    for (volatile uint32_t i = 0; i < 10; i++) {}
    HAL_GPIO_WritePin(us_sensor->TRIG_Port, us_sensor->TRIG_Pin, GPIO_PIN_RESET);
}

void US_Update(US_SENSOR* us_sensor){
	uint32_t echo_duration = us_sensor->echo_end - us_sensor->echo_start;
    us_sensor->distance_cm = (echo_duration * 0.0343) / 2;

}
