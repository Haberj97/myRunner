/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for player.c
*/

#ifndef __PLAYER__
#define __PLAYER__

#include "structs.h"
#include "audio.h"
#include "stage.h"

void do_player(App *app, Stage *stage, Entity *player, SDL_Texture *bullet_texture);
void fire_bullet(Stage *stage,Entity *player, SDL_Texture *bullet_texture);
void clip_player(Entity *player);

#endif /* PLAYER */
