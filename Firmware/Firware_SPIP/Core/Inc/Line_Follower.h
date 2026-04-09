/*
 * Line_Follower.h
 *
 *  Created on: Apr 8, 2026
 *      Author: hugow
 */

#ifndef INC_LINE_FOLLOWER_H_
#define INC_LINE_FOLLOWER_H_

#include "stm32g4xx_hal.h"
#include <stdint.h>

#define MAX_NUM_SENSORS 4

typedef struct {
    GPIO_TypeDef* sensor_ports[MAX_NUM_SENSORS];
    uint16_t      sensor_pins[MAX_NUM_SENSORS];
    uint8_t       num_sensors;
    uint8_t       sensor_values[MAX_NUM_SENSORS];
    int           position;
} LineFollower;

extern LineFollower h_lineFollower;

void LF_Init(LineFollower* lf,GPIO_TypeDef* ports[MAX_NUM_SENSORS],uint16_t pins[MAX_NUM_SENSORS],uint8_t num_sensors);

void LF_ReadSensors(LineFollower* lf);

void LF_Update(LineFollower* lf);

#endif /* INC_LINE_FOLLOWER_H_ */
