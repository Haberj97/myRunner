/*
** ETNA PROJECT, 2022
** TIC-DVC1/Runner
** File description:
**  this file contains all functions related with the stage
**
*/


#include "stage.h"

static int stageResetTimer;
static int highscore;

static Star stars[MAX_STARS];
Highscores highscores[MAX_HIGHSCORES];
static SDL_Texture *background_texture; 
static SDL_Texture *explosion_texture; 
static SDL_Texture *point_texture;
static SDL_Texture *player_texture;
static SDL_Texture *bullet_texture;
static SDL_Texture *meteore_texture;
static Entity *player ;

void init_highscores_table();
void draw_highscores(App *app );
void add_highscore(int score);



void init_stage(App *app, Stage *stage){
	memset(stage, 0, sizeof(Stage));
	memset(app->keyboard, 0, sizeof(int) * MAX_KEYBOARD_KEYS);
	init_linked_lists(stage);
	init_textures(app);
	reset_stage(stage);
	load_music("ressources/music.ogg");
	play_music(1);
	stage->stage_is_running = 0;
}

void reset_stage(Stage *stage){
	free_all_linked_lists(stage);
	stage->turn = 0;
	stage->score = 0;
	init_linked_lists(stage);
	init_player(stage,player_texture);
	init_stars(stars);
	stage->meteore_spawn_timer = 0;
	stageResetTimer = FPS * 3;
}

void init_textures(App *app){
	explosion_texture = load_texture(app,"ressources/explosion.png");
	background_texture = load_texture(app,"ressources/background.png");
	point_texture = load_texture(app,"ressources/bonus_point.png");
	player_texture = load_texture(app,"ressources/player.png");
	bullet_texture = load_texture(app,"ressources/bullet.png");
	meteore_texture = load_texture(app,"ressources/meteore.png");
}

void init_player(Stage *stage,SDL_Texture *player_texture){
	player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));
	stage->fighter_tail->next = player;
	stage->fighter_tail = player;
	player->health = 1;
	player->x = 100;
	player->y = 100;
    player->width = 100;
    player->height = 100;    
    player->texture = player_texture;
	player->side = SIDE_PLAYER;
}

void logic(App *app, Stage *stage)
{
	do_background(stage);
	do_stars(stars);
	if(stage->stage_is_running != 1){
	 	init_highscores_table();
	}
	if (app->keyboard[SDL_SCANCODE_E] && stage->stage_is_running == 0){
		stage->stage_is_running = 1;
	}

	if(stage->stage_is_running == 1){
		do_player(app, stage, player, bullet_texture);
		do_element(stage);
		do_bullets(stage);
		spawn_meteore(stage, meteore_texture);
		clip_player(player);
		do_explosions(stage);
		do_debris(stage);
		do_point(stage, player);
		score_increaser(stage);
	}
	if(stage->stage_is_running == 1 && app->keyboard[SDL_SCANCODE_P]){
	 	stage->stage_is_running = 3;
	}
	if(stage->stage_is_running == 3 && app->keyboard[SDL_SCANCODE_O]){
	 	stage->stage_is_running = 1;
	}
	if (player == NULL && --stageResetTimer <= 0 && stage->stage_is_running == 1){ 
		highscore = MAX(stage->score, highscore);
		add_highscore(stage->score);
		stage->stage_is_running = 2;
		reset_stage(stage);
	}
	if(stage->stage_is_running == 2 && app->keyboard[SDL_SCANCODE_E]){
	 	stage->stage_is_running = 1;
	 	reset_stage(stage);
	}
}

void draw(App *app, Stage *stage){
	draw_background(app, stage, background_texture);
	draw_head_up_display(app ,stage, highscore);
	draw_stars(app, stars);
	if(stage->stage_is_running != 1){
		draw_highscores(app);
	}
	draw_fighters(app , stage);
	draw_points_pods(app, stage);
	draw_debris(app , stage);
	draw_explosions(app, stage, explosion_texture);
	draw_bullets(app, stage);
}

	
int hit(Entity *entity,Stage *stage){
	Entity *element;
	for (element = stage->fighter_head.next ; element != NULL ; element = element->next){
		if (element->side != entity->side && collision(entity->x, entity->y, entity->width, entity->height, element->x, element->y, element->width, element->height)){
			if (element == player){
				play_sound(SND_PLAYER_DIE, CH_PLAYER);
			}else{
				add_point(stage, point_texture, element->x + element->width / 2, element->y + element->height / 2);
				play_sound(SND_METEORE_DIE, CH_ANY);
			}
			entity->health = 0;
			element->health = 0;
			add_explosions(stage, element->x, element->y, 32);
			add_debris(stage ,element);
			return 1;
		}
	}
	return 0;
}

void do_element(Stage *stage){
	Entity *element;
	Entity *previous;
	
	previous = &stage->fighter_head;
	
	for (element = stage->fighter_head.next ; element != NULL ; element = element->next){
		element->x += element->dx;
		element->y += element->dy;
		if (element != player && element->x < -element->width){
			element->health = 0;
		}
		if (element->health == 0){
			if (element == player){
				player = NULL;
				play_sound(SND_PLAYER_DIE, CH_PLAYER);
			}
			if (element == stage->fighter_tail){
				stage->fighter_tail = previous;
			}
			previous->next = element->next;
			free(element);
			element = previous;
		}
		previous = element;
	}
}

// TEST 


void init_highscores_table(){
	memset(highscores, 0, sizeof(Highscores));
	for (int i = 0 ; i < MAX_HIGHSCORES ; i++){
		highscores->highscore[i].score = MAX_HIGHSCORES - i;
	}
}

void draw_highscores(App *app){
	int	y = 150;
	draw_text(app, 425, 70, 255, 255, 255, "LEADER BOARD");
	for (int i = 0 ; i < MAX_HIGHSCORES ; i++){
		if (highscores->highscore[i].recent){
			draw_text(app, 425, y, 255, 255, 0, "#%d ================> %03d", (i + 1), highscores->highscore[i].score);
		}else{
			draw_text(app, 425, y, 255, 255, 255, "%d ================> %03d", (i + 1), highscores->highscore[i].score);
		}
		y += 50;
	}
	draw_text(app,425, 600, 255, 255, 255, "PRESS E TO PLAY!");
}

void add_highscore(int score){
	Highscore new_higscores[MAX_HIGHSCORES + 1];
	for (int i = 0 ; i < MAX_HIGHSCORES ; i++)
	{
		new_higscores[i] = highscores->highscore[i];
		new_higscores[i].recent = 0;
	}
	new_higscores[MAX_HIGHSCORES].score = score;
	new_higscores[MAX_HIGHSCORES].recent = 1;
	
	for(int i=0 ,j=0,k=0,c=0;i<MAX_HIGHSCORES;i++){
    	if( new_higscores[i].score < new_higscores[i-1].score ){ // si l’élément est mal placé
			j = 0;
			while ( new_higscores[j].score < new_higscores[i].score ) j++; // cette boucle sort par j = la nouvelle position de l’élément
			c = new_higscores[i].score; // ces 2 lignes servent a translater les cases en avant pour pouvoir insérer l’élément a sa nouvelle position
			for( k = i-1 ; k >= j ; k-- ) new_higscores[k+1].score = new_higscores[k].score;
			new_higscores[j].score = c; // l'insertion
    	}
	}
	memset(highscores, 0, sizeof(Highscores));
	for (int i = 0 ; i < MAX_HIGHSCORES ; i++)
	{
		highscores->highscore[i] = new_higscores[i];
	}

}