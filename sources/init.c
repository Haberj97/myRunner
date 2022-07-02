/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions used to initialize the sdl_framework
**
*/

#include "init.h"

void init_sdl(App *app){
    int renderer_flags , window_flags;
    renderer_flags = SDL_RENDERER_ACCELERATED;
    window_flags = 0;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
		printf("Couldn't initialize SDL Mixer\n");
		exit(1);
	}

	Mix_AllocateChannels(MAX_SND_CHANNELS);
    SDL_ShowCursor(0);
    app->window = SDL_CreateWindow("RUNNER", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,WINDOW_HEIGHT,window_flags);
    //memset(app->keyboard, 0, sizeof(int) * MAX_KEYBOARD_KEYS);
    if(!app->window){
        printf("Failed to open %d x %d window: %s\n", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_GetError());
		exit(1);
    }
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    
    app->renderer = SDL_CreateRenderer(app->window, -1, renderer_flags);
    
    if(!app->renderer){
        printf("Failed to create renderer : %s\n",SDL_GetError());
        exit(1);
    }
    
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}