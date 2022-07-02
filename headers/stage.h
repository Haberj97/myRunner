/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for stage.c
*/

#ifndef __STAGE__
#define __STAGE__

#include "defs.h"
#include "structs.h"
#include "draw_interface.h"
#include "collision.h"
#include "audio.h"
#include "text.h"
#include "memory.h"
#include "draw_element.h"
#include "score.h"
#include "linked_lists.h"
#include "stars.h"
#include "explosion.h"
#include "player.h"
#include "meteore.h"
#include "bullet.h"
#include "background.h"
#include <stdlib.h>
#include <stdio.h>
#include "debri.h"

void init_stage(App *app , Stage *stage);
void reset_stage(Stage *stage);
void init_textures(App *app);
void init_player(Stage *stage,SDL_Texture *player_texture);
void logic(App *app, Stage *stage);
void draw(App *app, Stage *stage);
int hit(Entity *b,Stage *stage);
void do_element(Stage *stage);


#endif /* STAGE */