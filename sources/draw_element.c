/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with elements drawing
*/

#include "draw_element.h"

void draw_points_pods(App *app,Stage *stage){
	Entity *element;
	for (element = stage->points_head.next ; element != NULL ; element = element->next){
		blit(app,element->texture, element->x, element->y, element->width, element->height);
	}
}

void draw_head_up_display(App *app , Stage *stage, int highscore){
	draw_text(app,10, 10, 255, 255, 255, "SCORE: %03d", stage->score);

	if (stage->score > 0 && stage->score == highscore){
		draw_text(app,960, 10, 0, 255, 0, "HIGH SCORE: %03d", highscore);
	}
	else{
		draw_text(app,960, 10, 255, 255, 255, "HIGH SCORE: %03d", highscore);
	}
}

void draw_fighters(App *app, Stage *stage){
	Entity *figther;
	for (figther = stage->fighter_head.next ; figther != NULL ; figther = figther->next){
		blit(app,figther->texture, figther->x, figther->y,figther->width, figther->height);
	}
}

void draw_bullets(App *app, Stage *stage){
	Entity *bullet;
	for (bullet = stage->bullet_head.next ; bullet != NULL ; bullet = bullet->next){
		blit(app,bullet->texture, bullet->x, bullet->y,bullet->width,bullet->height);
	}
}

void draw_stars(App *app,Star *stars){
	int count;
	for (int i = 0 ; i < MAX_STARS ; i++){
		count = 32 * stars[i].speed;
		SDL_SetRenderDrawColor(app->renderer, count, count, count, 255);
		SDL_RenderDrawLine(app->renderer, stars[i].x, stars[i].y, stars[i].x + 3, stars[i].y);
	}
}

void draw_debris(App *app ,Stage *stage){
	Debris *debri;
	for (debri = stage->debris_head.next ; debri != NULL ; debri = debri->next){
		blit_rect(app, debri->texture, &debri->rect, debri->x, debri->y);
	}
}

void draw_explosions(App *app, Stage *stage, SDL_Texture *explosion_texture){
	
	Explosion *explosion;
	SDL_SetRenderDrawBlendMode(app->renderer, SDL_BLENDMODE_ADD);
	SDL_SetTextureBlendMode(explosion_texture, SDL_BLENDMODE_ADD);
	
	for (explosion = stage->explosion_head.next ; explosion != NULL ; explosion = explosion->next){
		
		SDL_SetTextureColorMod(explosion_texture, explosion->red, explosion->green, explosion->blue);
		SDL_SetTextureAlphaMod(explosion_texture, explosion->alpha);
		SDL_Rect dest;
    	dest.x = explosion->x;
    	dest.y = explosion->y;

		SDL_QueryTexture(explosion_texture, NULL, NULL, &dest.w, &dest.h);
    	SDL_RenderCopy(app->renderer, explosion_texture, NULL, &dest);
	}
	
	SDL_SetRenderDrawBlendMode(app->renderer, SDL_BLENDMODE_NONE);
}