/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with debri's management
**
*/

#include "debri.h"

void do_debris(Stage *stage){
	Debris *debris;
	Debris *previous_debris;
	previous_debris = &stage->debris_head;
	for (debris = stage->debris_head.next ; debris != NULL ; debris = debris->next){
		debris->x += debris->dx;
		debris->y += debris->dy;
		debris->dy += 0.5;
		if (--debris->life <= 0){
			if (debris == stage->debris_tail){
				stage->debris_tail = previous_debris;
			}
			previous_debris->next = debris->next;
			free(debris);
			debris = previous_debris;
		}
		previous_debris = debris;
	}
}

void add_debris(Stage *stage ,Entity *element){
	Debris *debri;
	int x;
	int y;
	int width;
	int height;
	width = element->width / 2;
	height = element->height / 2;
	for (y = 0 ; y <= height ; y += height){
		for (x = 0 ; x <= width ; x += width){
			debri = malloc(sizeof(Debris));
			memset(debri, 0, sizeof(Debris));
			stage->debris_tail->next = debri;
			stage->debris_tail = debri;
			debri->x = element->x + element->width / 2;
			debri->y = element->y + element->height / 2;
			debri->dx = (rand() % 5) - (rand() % 5);
			debri->dy = -(5 + (rand() % 12));
			debri->life = FPS * 2;
			debri->texture = element->texture;
			debri->rect.x = x;
			debri->rect.y = y;
			debri->rect.w = width;
			debri->rect.h = height;
		}
	}
}