/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for collision.c
*/

#ifndef __COLLISION__
#define __COLLISION__

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

#endif /* COLLISION */