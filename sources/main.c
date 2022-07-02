/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file is the entry point for this project
**
*/

#include "main.h"

int main (void){
    long then;
    float remainder;
    App *app = malloc(sizeof(App));
    Stage *stage = malloc(sizeof(Stage));
    init_sdl(app);
    init_sounds();
    init_stage(app,stage);
    init_fonts(app);
    then = SDL_GetTicks();
    remainder = 0;
    game_loop(app, stage, &then, &remainder);
    return 0;
}
