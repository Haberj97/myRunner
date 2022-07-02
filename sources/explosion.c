/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with the explosions
**
*/

#include "explosion.h"

void add_explosions(Stage *stage ,int x, int y, int num){
	Explosion *explosion;
	for (int i = 0 ; i < num ; i++){
		explosion = malloc(sizeof(Explosion));
		memset(explosion, 0, sizeof(Explosion));
		
		stage->explosion_tail->next = explosion;
		stage->explosion_tail = explosion;
		explosion->x = x + (rand() % 32) - (rand() % 32);
		explosion->y = y + (rand() % 32) - (rand() % 32);
		explosion->dx = (rand() % 10) - (rand() % 10);
		explosion->dy = (rand() % 10) - (rand() % 10);
		explosion->dx /= 10;
		explosion->dy /= 10;

		switch (rand() % 4){
			case 0:
				explosion->red = 255;
				break;
			case 1:
				explosion->red = 255;
				explosion->green = 128;
				break;
			case 2:
				explosion->red = 255;
				explosion->green = 255;
				break;
			default:
				explosion->red = 255;
				explosion->green = 255;
				explosion->blue = 255;
				break;
		}
		explosion->alpha = rand() % FPS * 3;
	}
}

void do_explosions(Stage *stage){
	Explosion *explosion;
	Explosion *previous;
	previous = &stage->explosion_head;

	for (explosion = stage->explosion_head.next ; explosion != NULL ; explosion = explosion->next){
		explosion->x += explosion->dx;
		explosion->y += explosion->dy;
		if (--explosion->alpha <= 0){
			if (explosion == stage->explosion_tail){
				stage->explosion_tail = previous;
			}
			previous->next = explosion->next;
			free(explosion);
			explosion = previous;
		}
		previous = explosion;
	}
}


