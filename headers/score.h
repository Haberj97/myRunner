/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for score.c
*/

#ifndef __SCORE__
#define __SCORE__

#include "structs.h"
#include "audio.h"
#include "collision.h"

void score_increaser(Stage *stage);
void do_point(Stage *stage,Entity *player);
void add_point(Stage *stage ,SDL_Texture *point_texture, int x, int y);

#endif /* SCORE */