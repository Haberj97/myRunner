/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for game_loop.c
*/

#ifndef __GAME_LOOP__
#define __GAME_LOOP__

#include "structs.h"
#include "draw_interface.h"
#include "input.h"
#include "stage.h"
#include "frame.h"

void game_loop(App *app, Stage *stage, long* then, float *remainder);

#endif /* GAME LOOP */