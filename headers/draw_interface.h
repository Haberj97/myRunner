/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for draw_interface.c
*/

#ifndef __DRAW__
#define __DRAW__

#include "sdl2_libs.h"
#include "structs.h"

void prepare_scene(App *app);
void present_scene(App *app);
SDL_Texture *load_texture(App *app,char *path);
void blit(App *app ,SDL_Texture *texture, float x, float y,int width, int height);
void blit_rect(App *app ,SDL_Texture *texture, SDL_Rect *src, int x, int y);

#endif /* DRAW */