/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related to background management
**
*/


#include "background.h"

void do_background(Stage *stage){
	if(--stage->background_pos_x < -WINDOW_WIDTH){
		stage->background_pos_x  = 0;
	}
}

void draw_background(App *app,Stage *stage,SDL_Texture *background_texture){
	SDL_Rect dest;
	for (int x = stage->background_pos_x ; x < WINDOW_WIDTH ; x += WINDOW_WIDTH){
		dest.x = x;
		dest.y = 0;
		dest.w = WINDOW_WIDTH;
		dest.h = WINDOW_HEIGHT;
		SDL_RenderCopy(app->renderer, background_texture, NULL, &dest);
	}
}