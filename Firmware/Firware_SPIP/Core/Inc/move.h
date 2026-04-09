/*
 * mouvement.h
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */


#ifndef INC_MOVE_H_
#define INC_MOVE_H_

#include <control.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {STOP,MOVE_FORWARD,TURN} STATUS;

typedef struct{
    STATUS status;
    int32_t d_target_cnt;
    int32_t d_ticks_left_actual;
    int32_t d_ticks_right_actual;
    int32_t speed_cnt;
    float track_width;
    float radius;
    float angle_target_rad;
    float angle_actual_rad;
} MOVE;



void move_init(MOVE * move,ENCODER *encoder,float track_width,float radius);
void move_forward(MOVE *move,ENCODER *encoder,float d_target_cm, float speed_cm_s);
void turn(MOVE *move, ENCODER *encoder,float angle_target_rad, float speed_cm_s);
void move_update(MOVE *move, CONTROL *control_left, CONTROL *control_right, ENCODER *encoder_left, ENCODER *encoder_right);

#endif
