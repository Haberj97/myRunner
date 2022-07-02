/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for background.c
*/

#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "defs.h"
#include "structs.h"
void do_background(Stage *stage);
void draw_background(App *app,Stage *stage,SDL_Texture *background_texture);
#endif /* BACKGROUND */
