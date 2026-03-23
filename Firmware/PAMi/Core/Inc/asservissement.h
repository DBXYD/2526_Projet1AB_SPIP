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

typedef struct asservissement{
	float consigne_vitesse_g;
	float consigne_vitesse_d;
	float Kp;
	float Ki;
} ASSERVISSEMENT;

void asservissement_init(ASSERVISSEMENT * asservissement,float Kp,float Ki);
void asservissement_update(ASSERVISSEMENT *asservissement, MOTOR *motor_g, MOTOR *motor_d, ENCODER *encoder_g, ENCODER *encoder_d);
void asservissement_set_vitesse(ASSERVISSEMENT * asservissement, float speed_g, float speed_d);



#endif /* INC_ASSERVISSEMENT_H_ */
