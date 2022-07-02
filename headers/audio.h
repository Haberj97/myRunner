/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for audio.c
*/

#ifndef __AUDIO__
#define __AUDIO__

#include "sdl2_libs.h"
#include "defs.h"

void init_sounds(void);
void load_music(char *filename);
void play_music(int loop);
void play_sound(int id, int channel);
void load_sounds(void);


#endif /* AUDIO */