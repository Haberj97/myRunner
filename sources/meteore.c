/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related to meteores spawn
**
*/

#include "meteore.h"

void spawn_meteore(Stage *stage, SDL_Texture *meteore_texture){
	Entity *meteore;
	if (--stage->meteore_spawn_timer <= 0){
		meteore = malloc(sizeof(Entity));
		memset(meteore, 0, sizeof(Entity));
		stage->fighter_tail->next = meteore;
		stage->fighter_tail = meteore;
		meteore->x = WINDOW_WIDTH;
		meteore->y = rand() % WINDOW_HEIGHT;
        meteore->width = 100;
        meteore->height = 100;    
        meteore->texture = meteore_texture;
		meteore->dx = -(2 + (rand() % 4));
		meteore->side = SIDE_METEORE;
		meteore->health = 1;
		meteore->reload = FPS * (1 + (rand() % 3));
		stage->meteore_spawn_timer = 30 + (rand() % FPS);
	}
}