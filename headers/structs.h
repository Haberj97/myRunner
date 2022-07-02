/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file manage all structures declaration.
*/

#ifndef __STRUCTS__
#define __STRUCTS__

#include "sdl2_libs.h"
#include "defs.h"

typedef struct Entity Entity;
typedef struct Debris Debris;
typedef struct Explosion Explosion;

typedef struct {
    SDL_Renderer    *renderer;
	SDL_Window      *window;
    int             keyboard[MAX_KEYBOARD_KEYS];
} App;

struct Entity {
    float           x;
    float           y;
    int             width;
    int             height;
    float           dx;
    float           dy;
    int             health;
    int             side;
    int             reload;
    SDL_Texture     *texture;
    Entity          *next;
};

struct Explosion{
	float           x;
	float           y;
	float           dx;
	float           dy;
	int             red;
    int             green;
    int             blue;
    int             alpha;
	Explosion       *next;
};

struct Debris{
	float           x;
	float           y;
	float           dx;
	float           dy;
	SDL_Rect        rect;
	SDL_Texture     *texture;
	int             life;
	Debris          *next;
};

typedef struct {
    Entity          fighter_head, *fighter_tail;
    Entity          bullet_head, *bullet_tail;
    Explosion       explosion_head, *explosion_tail;
	Debris          debris_head, *debris_tail;
    Entity          points_head, *points_tail;
    int             score;
    int             turn;
    int             meteore_spawn_timer;
    int             background_pos_x;
    int             stage_is_running;
} Stage;

typedef struct {
	int             x;
	int             y;
	int             speed;  
} Star;

typedef struct {
	int recent;
	int score;
} Highscore;

typedef struct {
	Highscore highscore[MAX_HIGHSCORES];
} Highscores;

#endif /* STRUCTS */