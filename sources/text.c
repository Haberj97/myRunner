/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with the text management
**
*/

#include "text.h"

static SDL_Texture *font_texture;
static char draw_text_buffer[MAX_LINE_LENGTH];

void init_fonts(App *app){
	font_texture = load_texture(app,"ressources/font.png");
}

void draw_text(App *app, int x, int y, int red, int green, int blue, char *format, ...){
	int i;
	int length;
	int character;
	SDL_Rect rect;
	va_list args;
	
	memset(&draw_text_buffer, '\0', sizeof(draw_text_buffer));
	va_start(args, format);
	vsprintf(draw_text_buffer, format, args);
	va_end(args);
	length = strlen(draw_text_buffer);
	rect.w = GLYPH_WIDTH;
	rect.h = GLYPH_HEIGHT;
	rect.y = 0;	
	SDL_SetTextureColorMod(font_texture, red, green, blue);
	for (i = 0 ; i < length ; i++){
		character = draw_text_buffer[i];
		if (character >= ' ' && character <= 'Z'){
			rect.x = (character - ' ') * GLYPH_WIDTH;
			blit_rect(app, font_texture, &rect, x, y);
			x += GLYPH_WIDTH;
		}
	}
}