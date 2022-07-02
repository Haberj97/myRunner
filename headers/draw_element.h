/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for draw_element.c
*/

#ifndef __DRAW_ELEMENT__
#define __DRAW_ELEMENT__

#include "structs.h"
#include "text.h"

void draw_points_pods(App *app,Stage *stage);
void draw_head_up_display(App *app , Stage *stage, int highscore);
void draw_fighters(App *app, Stage *stage);
void draw_bullets(App *app, Stage *stage);
void draw_stars(App *app,Star *stars);
void draw_debris(App *app ,Stage *stage);
void draw_explosions(App *app, Stage *stage, SDL_Texture *explosion_texture);

#endif /* DRAW_ELEMENT */