/*
 * asservissement.h
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#ifndef INC_ASSERVISSEMENT_H_
#define INC_ASSERVISSEMENT_H_

#include "motor.h"
#include "encoder.h"

typedef struct{
	float ref_speed;
	float Kp;
	float Ki;
	int32_t error_cumul;

} ASSERVISSEMENT;

void asser_init(ASSERVISSEMENT * asser,float Kp,float Ki);
void asser_update(ASSERVISSEMENT *asser, MOTOR *motor, ENCODER *encoder);
void asser_set_speed(ASSERVISSEMENT * asser, float ref_speed);
void error_reset(ASSERVISSEMENT* asser);


#endif /* INC_ASSERVISSEMENT_H_ */
