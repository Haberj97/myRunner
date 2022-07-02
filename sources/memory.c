/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions used to free linked_lists used memory
**
*/

#include "memory.h"

void free_all_linked_lists(Stage *stage) {
	Entity *e;
	Explosion *ex;
	Debris *d;

	while (stage->fighter_head.next){
		e = stage->fighter_head.next;
		stage->fighter_head.next = e->next;
		free(e);
	}
	
	while (stage->bullet_head.next){
		e = stage->bullet_head.next;
		stage->bullet_head.next = e->next;
		free(e);
	}

	while (stage->explosion_head.next){
		ex = stage->explosion_head.next;
		stage->explosion_head.next = ex->next;
		free(ex);
	}

	while (stage->debris_head.next){
		d = stage->debris_head.next;
		stage->debris_head.next = d->next;
		free(d);
	}
    
	while (stage->points_head.next){
		e = stage->points_head.next;
		stage->points_head.next = e->next;
		free(e);
	}
}