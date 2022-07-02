/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
** 		this file is an header that manage all enums / macro declarations 
*/

#ifndef __DEFS__
#define __DEFS__

#define WINDOW_WIDTH            1280
#define WINDOW_HEIGHT           720
#define FPS                     60

#define MAX_KEYBOARD_KEYS       350

#define PLAYER_SPEED            6
#define PLAYER_BULLET_SPEED     16

#define SIDE_PLAYER             0
#define SIDE_METEORE            1

#define MAX_STARS               650

#define MAX_SND_CHANNELS        8

#define MAX_LINE_LENGTH 		1024

#define MAX_HIGHSCORES 			5

enum
{
	CH_ANY = -1,
	CH_PLAYER,
	CH_ALIEN_FIRE,
	CH_POINT
};

enum
{
	SND_PLAYER_FIRE,
	SND_PLAYER_DIE,
	SND_METEORE_DIE,
	SND_POINT,
	SND_MAX
};

#endif /* DEFS */