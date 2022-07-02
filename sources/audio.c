
/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related to audio management
**
*/


#include "audio.h"

static Mix_Chunk *sounds[SND_MAX];
static Mix_Music *music;

void init_sounds(void){
	memset(sounds, 0, sizeof(Mix_Chunk*) * SND_MAX);
	music = NULL;
	load_sounds();
}

void load_music(char *filename){
	if (music != NULL){
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		music = NULL;
	}
	music = Mix_LoadMUS(filename);
}

void play_music(int loop){
	Mix_PlayMusic(music, (loop) ? -1 : 0);
}

void play_sound(int id, int channel){
	Mix_PlayChannel(channel, sounds[id], 0);
}

void load_sounds(void){
	sounds[SND_PLAYER_FIRE] = Mix_LoadWAV("ressources/fire.ogg");
	sounds[SND_METEORE_DIE] = Mix_LoadWAV("ressources/meteore_explosion.ogg");
	sounds[SND_PLAYER_DIE] = Mix_LoadWAV("ressources/game_over.ogg");
	sounds[SND_POINT] = Mix_LoadWAV("ressources/bonus_point.ogg");
}
