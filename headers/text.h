/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header for text.c
*/

#ifndef __TEXT__
#define __TEXT__

#define GLYPH_HEIGHT    28
#define GLYPH_WIDTH     18

#include "draw_interface.h"
void init_fonts(App *app);
void draw_text(App *app, int x, int y, int red, int green, int blue, char *format, ...);

#endif /* TEXT */