/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with score and pointss
**
*/

#include "score.h"

void score_increaser(Stage *stage){
	if (stage->turn <= 350){
		stage->turn ++;
	}else if (stage->turn > 350){
		stage->turn = 0;
		stage->score++;
	}
}

void do_point(Stage *stage,Entity *player){
	Entity *point;
	Entity *previous;
	previous = &stage->points_head;

	for (point = stage->points_head.next ; point != NULL ; point = point->next){
		if (point->x < 0){
			point->x = 0;
			point->dx = -point->dx;
		}
		if (point->x + point->width > WINDOW_WIDTH){
			point->x = WINDOW_WIDTH - point->width;
			point->dx = -point->dx;
		}
		if (point->y < 0){
			point->y = 0;
			point->dy = -point->dy;
		}
		if(point->y + point->height > WINDOW_HEIGHT){
			point->y = WINDOW_HEIGHT - point->height;
			point->dy = -point->dy;
		}
		point->x += point->dx;
		point->y += point->dy;
		if (player != NULL && collision(point->x, point->y, point->width, point->height, player->x, player->y, player->width, player->height)){
			point->health = 0;
			stage->score+=5;
			play_sound(SND_POINT, CH_POINT);
		}
		if (--point->health <= 0){
			if (point == stage->points_tail){
				stage->points_tail = previous;
			}
			previous->next = point->next;
			free(point);
			point = previous;
		}
		previous = point;
	}
}

void add_point(Stage *stage ,SDL_Texture *point_texture, int x, int y){
	Entity *point;
	point = malloc(sizeof(Entity));
	memset(point, 0, sizeof(Entity));
	stage->points_tail->next = point;
	stage->points_tail = point;
	point->x = x;
	point->y = y;
	point->dx = -(rand() % 5);
	point->dy = (rand() % 5) - (rand() % 5);
	point->health = FPS * 10;
	point->texture = point_texture;
	point->height = 50;
	point->width = 50;
	point->x -= point->width / 2;
	point->y -= point->height / 2;
}