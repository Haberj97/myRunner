/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions used for the input captation
**
*/

#include "input.h"

void input_handler(App *app, Stage *stage){
    
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                free_all_linked_lists(stage);
                SDL_DestroyRenderer(app->renderer);
                SDL_DestroyWindow(app->window);
                free(app);
                free(stage);
                exit(0);
                break;
            case SDL_KEYDOWN:
                do_key_down(app,&event.key);
                break;
            case SDL_KEYUP:
                do_key_up(app,&event.key);
                break;
            default:
                break;
        
        }
    }
}

void do_key_down(App *app, SDL_KeyboardEvent *event){
    if(event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS){
        app->keyboard[event->keysym.scancode] = 1;
    }
}

void do_key_up(App *app, SDL_KeyboardEvent *event){
    if(event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS){
        app->keyboard[event->keysym.scancode] = 0;
    }
}
