/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for input.c
*/

#ifndef __INPUT__
#define __INPUT__

#include "sdl2_libs.h"
#include "structs.h"
#include "defs.h"
#include "memory.h"

void input_handler(App *app, Stage *stage);
void do_key_down(App *app, SDL_KeyboardEvent *event);
void do_key_up(App *app, SDL_KeyboardEvent *event);

#endif /* INPUT */