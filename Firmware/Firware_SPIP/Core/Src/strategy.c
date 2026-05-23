/*
 * strategy.c
 *
 *  Created on: Apr 9, 2026
 *      Author: lucasa
 */


#include "strategy.h"
#include <string.h>

MOTOR motor_left, motor_right;
ENCODER encoder_left, encoder_right;
CONTROL control_left, control_right;
MOVE move;


void strat_one(STATE * status, const char * color){
	switch (status->status_actual) {
		case INIT:
			HAL_Delay(2000);
			status->status_actual = MOVE_FORWARD_1;
			break;

		case MOVE_FORWARD_1:
			move_forward(&move, &encoder_left, 86.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_1;
			break;

		case WAIT_MOVE_FORWARD_1:
			if (move.status == STOP) {
				status->status_actual = END;
			}
			break;

		case END:
			break;

		default:
			break;
	}
}

void strat_two(STATE * status, const char * color){
	int sens = 1;
	if(strcmp(color, "yellow") == 0){
		sens = -1;
	}
	if(strcmp(color, "blue") == 0){
		sens = 1;
	}

	switch (status->status_actual) {
		case INIT:
			HAL_Delay(2000);
			status->status_actual = MOVE_FORWARD_1;
			break;

		case MOVE_FORWARD_1:
			move_forward(&move, &encoder_left, 96.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_1;
			break;

		case WAIT_MOVE_FORWARD_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = TURN_1;
			}
			break;

		case TURN_1:
			turn(&move, &encoder_left, sens * M_PI / 2, 10.0);
			status->status_actual = WAIT_TURN_1;
			break;

		case WAIT_TURN_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = MOVE_FORWARD_2;
			}
			break;

		case MOVE_FORWARD_2:
			move_forward(&move, &encoder_left, 67.5, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_2;
			break;

		case WAIT_MOVE_FORWARD_2:
			if (move.status == STOP) {
				status->status_actual = END;
			}
			break;

		case END:
			break;

		default:
			break;
	}
}

void strat_three(STATE * status, const char * color){
	int sens = 1;
	if(strcmp(color, "yellow") == 0){
		sens = -1;
	}
	if(strcmp(color, "blue") == 0){
		sens = 1;
	}

	switch (status->status_actual) {
		case INIT:
			HAL_Delay(2000);
			status->status_actual = MOVE_FORWARD_1;
			break;

		case MOVE_FORWARD_1:
			move_forward(&move, &encoder_left, 86.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_1;
			break;

		case WAIT_MOVE_FORWARD_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = TURN_1;
			}
			break;

		case TURN_1:
			turn(&move, &encoder_left, sens * M_PI / 2, 10.0);
			status->status_actual = WAIT_TURN_1;
			break;

		case WAIT_TURN_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = MOVE_FORWARD_2;
			}
			break;

		case MOVE_FORWARD_2:
			move_forward(&move, &encoder_left, 137.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_2;
			break;

		case WAIT_MOVE_FORWARD_2:
			if (move.status == STOP) {
				status->status_actual = END;
			}
			break;

		case END:
			break;

		default:
			break;
	}
}

void strat_four(STATE * status, const char * color){
	int sens = 1;
	if(strcmp(color, "yellow") == 0){
		sens = -1;
	}
	if(strcmp(color, "blue") == 0){
		sens = 1;
	}

	switch (status->status_actual) {
		case INIT:
			HAL_Delay(2000);
			status->status_actual = MOVE_FORWARD_1;
			break;

		case MOVE_FORWARD_1:
			move_forward(&move, &encoder_left, 154.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_1;
			break;

		case WAIT_MOVE_FORWARD_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = TURN_1;
			}
			break;

		case TURN_1:
			turn(&move, &encoder_left, sens * M_PI / 2, 10.0);
			status->status_actual = WAIT_TURN_1;
			break;

		case WAIT_TURN_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = MOVE_FORWARD_2;
			}
			break;

		case MOVE_FORWARD_2:
			move_forward(&move, &encoder_left, 55.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_2;
			break;

		case WAIT_MOVE_FORWARD_2:
			if (move.status == STOP) {
				status->status_actual = END;
			}
			break;

		case END:
			break;

		default:
			break;
	}
}

void strat_five(STATE * status, const char * color){
	int sens = 1;
	if(strcmp(color, "yellow") == 0){
		sens = -1;
	}
	if(strcmp(color, "blue") == 0){
		sens = 1;
	}

	switch (status->status_actual) {
		case INIT:
			HAL_Delay(2000);
			status->status_actual = MOVE_FORWARD_1;
			break;

		case MOVE_FORWARD_1:
			move_forward(&move, &encoder_left, 154.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_1;
			break;

		case WAIT_MOVE_FORWARD_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = TURN_1;
			}
			break;

		case TURN_1:
			turn(&move, &encoder_left, sens * M_PI / 2, 10.0);
			status->status_actual = WAIT_TURN_1;
			break;

		case WAIT_TURN_1:
			if (move.status == STOP) {
				HAL_Delay(500);
				status->status_actual = MOVE_FORWARD_2;
			}
			break;

		case MOVE_FORWARD_2:
			move_forward(&move, &encoder_left, 137.0, 20.0);
			status->status_actual = WAIT_MOVE_FORWARD_2;
			break;

		case WAIT_MOVE_FORWARD_2:
			if (move.status == STOP) {
				status->status_actual = END;
			}
			break;

		case END:
			break;

		default:
			break;
	}
}


void status_init(STATE * status){
	status->status_actual = INIT;
}
