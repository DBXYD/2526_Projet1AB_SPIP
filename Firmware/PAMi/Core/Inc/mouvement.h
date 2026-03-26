/*
 * mouvement.h
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */


#ifndef INC_MOUVEMENT_H_
#define INC_MOUVEMENT_H_

#include "asservissement.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {STOP,AVANCER,TOURNER} ETAT;

typedef struct{
    ETAT etat;
    float track_width;
    float radius;
    int32_t d_target_cnt;
    int32_t d_ticks_g_actual;
    int32_t d_ticks_d_actual;
    int32_t speed_cnt;
    //bool angle_positif;
} MVTCTRL;

void move_init(MVTCTRL * mvt,float track_width,float radius);
void avancer(MVTCTRL *mvt, MOTOR *motor, ENCODER *encoder,float d_target_cm, float speed_cm_s);

//void tourner(MVTCTRL *mvt, MOTOR *motor_g, ENCODER *encoder_g,float angle_deg,
		//float vitesse);

void mouvement_update(MVTCTRL *mvt, ASSERVISSEMENT *asser_g, ASSERVISSEMENT *asser_d, ENCODER *encoder_g, ENCODER *encoder_d);

#endif
