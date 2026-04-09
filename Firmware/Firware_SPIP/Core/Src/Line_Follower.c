/*
 * Line_Follower.c
 *
 *  Created on: Apr 8, 2026
 *      Author: hugow
 */

#include "Line_Follower.h"

LineFollower h_lineFollower;

void LF_Init(LineFollower* lf,
             GPIO_TypeDef* ports[4],
             uint16_t pins[4],
             uint8_t num_sensors) {

	lf->num_sensors = num_sensors;

    for (uint8_t i = 0; i < lf->num_sensors; i++) {
        lf->sensor_ports[i] = ports[i];
        lf->sensor_pins[i] = pins[i];
    }
}

void LF_ReadSensors(LineFollower* lf) {
    for (uint8_t i = 0; i < lf->num_sensors; i++) {
        lf->sensor_values[i] = HAL_GPIO_ReadPin(lf->sensor_ports[i], lf->sensor_pins[i]);
    }
}

void LF_Update(LineFollower* lf){
	LF_ReadSensors(lf);
	lf->position = lf->sensor_values[0] * 1000 + lf->sensor_values[1] * 100 + lf->sensor_values[2] * 10 + lf->sensor_values[3];
};
