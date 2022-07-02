/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with the stars
**
*/


#include "stars.h"

void init_stars(Star *stars){
	for (int i = 0 ; i < MAX_STARS ; i++){
		stars[i].x = rand() % WINDOW_WIDTH;
		stars[i].y = rand() % WINDOW_HEIGHT;
		stars[i].speed = 1 + rand() % 8;
	}
}

void do_stars(Star *stars){
	for (int i = 0 ; i < MAX_STARS ; i++){
		stars[i].x -= stars[i].speed;
		if (stars[i].x < 0){
			stars[i].x = WINDOW_WIDTH + stars[i].x;
		}
	}
}

