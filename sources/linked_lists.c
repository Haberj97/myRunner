/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions used to init linked_lists
**
*/

#include "linked_lists.h"

void init_linked_lists(Stage *stage){
	stage->fighter_tail = &stage->fighter_head;
	stage->bullet_tail = &stage->bullet_head;
	stage->explosion_tail = &stage->explosion_head;
	stage->debris_tail = &stage->debris_head;
	stage->points_tail = &stage->points_head;
}