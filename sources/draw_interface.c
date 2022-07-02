/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with interface drawing
*/
#include "draw_interface.h"

void prepare_scene(App *app){
    SDL_SetRenderDrawColor(app->renderer,0, 0, 0, 255);
    SDL_RenderClear(app->renderer);
}

void present_scene(App *app){
    SDL_RenderPresent(app->renderer);
}

SDL_Texture *load_texture(App *app,char *path){
    SDL_Texture *texture ;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
    SDL_LOG_PRIORITY_INFO,"Load %s",path);
    texture = IMG_LoadTexture(app->renderer,path);
    return texture;
}

void blit(App *app ,SDL_Texture *texture, float x, float y,int width, int height){
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = width;
    dest.h = height;
    SDL_RenderCopy(app->renderer, texture, NULL, &dest);
}

void blit_rect(App *app ,SDL_Texture *texture, SDL_Rect *src, int x, int y){
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = src->w;
	dest.h = src->h;
	SDL_RenderCopy(app->renderer, texture, src, &dest);
}