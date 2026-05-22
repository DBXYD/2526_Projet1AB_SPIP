/*
 * mouvement.c
 *
 *  Created on: Mar 12, 2026
 *      Author: lucasa
 */

#include "move.h"
#include <stdio.h>

#define LINE_POSITION_CENTER 110
#define LINE_SPEED_CORRECTION_DIVIDER 3

void move_init(MOVE * move,ENCODER *encoder,float track_width,float radius){
	move->radius=radius;
	float perimeter_cm = 2.0f * M_PI * move->radius;
	float K=(encoder->cnt_tr/perimeter_cm);
	move->status=STOP;
	move->d_target_cnt=0;
	move->d_ticks_left_actual=0;
	move->d_ticks_right_actual=0;
	move->speed_cnt=0;
	move->track_width=track_width*K;
	move->angle_actual_rad=0;
	move->previous_speed_cnt=0;
	move->line_speed_adjusted=0;
}


void move_forward(MOVE * move, ENCODER *encoder,float d_target_cm, float speed_cm_s){
    float perimeter_cm = 2.0f * M_PI * move->radius;
    float K=(encoder->cnt_tr/perimeter_cm);
    move->d_target_cnt =d_target_cm*K;
    move->speed_cnt = (int32_t) (speed_cm_s*K) ;
    move->previous_speed_cnt = move->speed_cnt;
    move->line_speed_adjusted = 0;
    move->d_ticks_left_actual=0;
    move->d_ticks_right_actual=0;

    move->status = MOVE_FORWARD;

}

void turn (MOVE *move, ENCODER *encoder,float angle_target_rad, float speed_cm_s){
    float perimeter_cm = 2.0f * M_PI * move->radius;
    float K=(encoder->cnt_tr/perimeter_cm);
    move->angle_target_rad=angle_target_rad;
    move->speed_cnt = (int32_t) (speed_cm_s*K) ;
    move->previous_speed_cnt = move->speed_cnt;
    move->line_speed_adjusted = 0;
    move->d_ticks_left_actual=0;
    move->d_ticks_right_actual=0;
    move->status = TURN;
}


void move_update(MOVE *move, CONTROL *control_left, CONTROL *control_right, ENCODER *encoder_left, ENCODER *encoder_right,US_SENSOR* us_sensor, LineFollower *line_follower) {
	if (us_sensor->distance_cm > 0.0f && us_sensor->distance_cm  < 10.0f) {
	        control_set_speed(control_left, 0);
	        control_set_speed(control_right, 0);
	        return;
	}



	if (move->status == STOP){
	        control_set_speed(control_left, 0);
	        control_set_speed(control_right, 0);
	        return;
	    }

	move->d_ticks_left_actual += encoder_left->delta_ticks;
	move->d_ticks_right_actual += encoder_right->delta_ticks;

	int32_t speed_left = 0, speed_right = 0;
	int sens_left=1, sens_right=1, sens_a=1;

	if (encoder_right->delta_ticks<0){
		sens_right=-1;
	}
	if (encoder_left->delta_ticks<0){
		sens_left=-1;
			}
	if(move->angle_target_rad<0){
		sens_a=-1;
	}

	move->angle_actual_rad = abs(sens_left*move->d_ticks_left_actual + sens_right*move->d_ticks_right_actual)/move->track_width;

	if (move->status == MOVE_FORWARD){
		if (move-> d_ticks_left_actual*sens_left< move->d_target_cnt){
			speed_left = move->speed_cnt;
		}

		if (move->d_ticks_right_actual*sens_right < move->d_target_cnt){
			speed_right = -move->speed_cnt;
		}

		if (line_follower != NULL && speed_left != 0 && speed_right != 0) {
			int line_position = line_follower->position;

			if (line_position != LINE_POSITION_CENTER) {
				int32_t speed_correction;

				if (move->line_speed_adjusted == 0) {
					move->previous_speed_cnt = move->speed_cnt;
					move->line_speed_adjusted = 1;
				}

				speed_correction = move->previous_speed_cnt / LINE_SPEED_CORRECTION_DIVIDER;
				if (speed_correction < 1) {
					speed_correction = 1;
				}

				if (line_position == 1000 || line_position == 1100 || line_position == 100) {
					speed_left = move->previous_speed_cnt - speed_correction;
					speed_right = -(move->previous_speed_cnt + speed_correction);
				}
				else if (line_position == 1 || line_position == 11 || line_position == 10) {
					speed_left = move->previous_speed_cnt + speed_correction;
					speed_right = -(move->previous_speed_cnt - speed_correction);
				}
			}
			else if (move->line_speed_adjusted != 0) {
				speed_left = move->previous_speed_cnt;
				speed_right = -move->previous_speed_cnt;
				move->line_speed_adjusted = 0;
			}
		}

		control_set_speed(control_left,speed_left);
		control_set_speed(control_right,speed_right);
		if (speed_left == 0 && speed_right == 0){
			move->status = STOP;
		}
	}
	else if (move->status == TURN) {

		if(abs(move->angle_actual_rad)<=abs(move->angle_target_rad)){
			  speed_left = sens_a*move->speed_cnt;
			  speed_right = sens_a*move->speed_cnt;
			  control_set_speed(control_left,speed_left);
			  control_set_speed(control_right,speed_right);
		}
		if (speed_left == 0 && speed_right == 0){
			move->status = STOP;
		}
	}






}

