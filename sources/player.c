/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with player logic 
**
*/

#include "player.h"

void do_player(App *app, Stage *stage, Entity *player, SDL_Texture *bullet_texture){
	if (player != NULL){
		player->dx = player->dy = 0;
		if (player->reload > 0){
			player->reload--;
		}
		if(app->keyboard[SDL_SCANCODE_W]){
			player->dy = -PLAYER_SPEED;
		}
		if(app->keyboard[SDL_SCANCODE_S]){
			player->dy = PLAYER_SPEED;
		}
		if(app->keyboard[SDL_SCANCODE_A]){
			player->dx = -PLAYER_SPEED;
		}
		if(app->keyboard[SDL_SCANCODE_D]){
			player->dx = PLAYER_SPEED;
		}
		if (app->keyboard[SDL_SCANCODE_E] && player->reload <= 0 && stage->score >= 2){
			fire_bullet(stage, player, bullet_texture);
			play_sound(SND_PLAYER_FIRE, CH_PLAYER);
			stage->score -= 3;
		}
		hit(player,stage);
	}
}

void fire_bullet(Stage *stage,Entity *player, SDL_Texture *bullet_texture){
	Entity *bullet;
	bullet = malloc(sizeof(Entity));
	memset(bullet, 0, sizeof(Entity));
	stage->bullet_tail->next = bullet;
	stage->bullet_tail = bullet;
	bullet->x = player->x;
	bullet->y = player->y;
	bullet->dx = PLAYER_BULLET_SPEED;
	bullet->health = 1;
    bullet->width = 25;
    bullet->height = 25;    
    bullet->texture = bullet_texture;
	bullet->side = player->side;
	bullet->y += (player->height / 2) - (bullet->height / 2);
	bullet->side = SIDE_PLAYER;
	player->reload = 8;
}

void clip_player(Entity *player){
	if (player != NULL){
		if (player->x < 0){
			player->x = 0;
		}
		if (player->y < 0){
			player->y = 0;
		}
		if (player->x > WINDOW_WIDTH / 2){
			player->x = WINDOW_WIDTH / 2;
		}
		if (player->y > WINDOW_HEIGHT - player->height){
			player->y = WINDOW_HEIGHT - player->height;
		}
	}
}
