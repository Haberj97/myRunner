/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related to bullets creation
**
*/

#include "bullet.h"

void do_bullets(Stage *stage){
	Entity *bullet;
	Entity *previous;
	previous = &stage->bullet_head;

	for (bullet = stage->bullet_head.next ; bullet != NULL ; bullet = bullet->next){
		bullet->x += bullet->dx;
		bullet->y += bullet->dy;
		if (hit(bullet, stage) || bullet->x < -bullet->width || bullet->y < -bullet->height || bullet->x > WINDOW_WIDTH || bullet->y > WINDOW_HEIGHT){
			if (bullet == stage->bullet_tail){
				stage->bullet_tail = previous;
			}
			previous->next = bullet->next;
			free(bullet);
			bullet = previous;
		}
		previous = bullet;
	}
}