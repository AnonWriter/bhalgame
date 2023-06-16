#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include "libs/player.h"
#include "libs/enemies.h"
#include "libs/score.h"

void run();

int main(){
	run();
}

void run(){

	/* Inits */
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();

	init_s_coords(100);

	al_install_keyboard();

	/* ALLEGRO Variables */
	ALLEGRO_DISPLAY * display;
	const int dw = 640;
	const int dh = 640;
	display = al_create_display(dw, dh);

	ALLEGRO_KEYBOARD_STATE state;

	ALLEGRO_COLOR palette[5] = {
									al_premul_rgba(0,	0, 0, 255), 	//BLACK
									al_premul_rgba(255, 0, 0, 255), 	//RED
									al_premul_rgba(0, 255, 0, 255), 	//GREEN
									al_premul_rgba(0, 0, 255, 255), 	//BLUE
									al_premul_rgba(255, 255, 255, 255),	//WHITE
								};

	ALLEGRO_FONT * tex = al_load_ttf_font("./fonts/cmunci.ttf", 18, 0);

	/* Normal Variables */
	int x = dw / 2;
	int y = dh / 2;
	int center = 0;
	int e_center = 0;

	int score = 0;

	bool shooting = false;

	bool in_rx, in_lx;
	bool in_uy, in_dy;

	bool shift;

	char *labelx = "x = ";
	char *labely = "y = ";
	char *labels = "score:";
	char *coordx;

	int (*spointer)[1000] = get_s_coords();

	/* Movement Variables */
	int k = 5;

	/* Constant buffering */
	bool quit = false;
	while(!quit){
		/* bg */
		al_clear_to_color(palette[0]);

		// exit condition
		al_get_keyboard_state(&state);
		if(al_key_down(&state, ALLEGRO_KEY_ESCAPE)) quit = !quit;

		/* The drawwwwing */
		//rect_hitbox_draw(x, y, 10, 10, hitbox);

		// player
		shift = al_key_down(&state, ALLEGRO_KEY_LSHIFT);
		if(shift){
			k = 3;
			rect_hitbox_draw(x, y, 10, 10, palette[1]);
		}
		else {
			k = 10;
			rect_hitbox_draw(x, y, 10, 10, palette[2]);
		}

		moving(&state, &x, &y, dw - 165, dh, k);

		if(al_key_down(&state, ALLEGRO_KEY_Z)){
			center = get_center(x, 10);
			shooting = true;
		}
		
		shoot(center, y, 25, 100, &shooting);

		sprintf(coordx, "%d", x);

		al_draw_text(tex, palette[1], 0, 0, 0, labelx);
		al_draw_text(tex, palette[1], 40, 0, 0, coordx);
	
		sprintf(coordx, "%d", y);

		al_draw_text(tex, palette[3], 0, 20, 0, labely);
		al_draw_text(tex, palette[3], 40, 20, 0, coordx);

		// enemies
		e_center = get_enemy_center(30, 10);
		draw_enemy_hitbox(200, 60);
		enemy_collision(100, spointer, 200, 60, &score);

		sprintf(coordx, "%d", score);
		al_draw_text(tex, palette[4], 500, 100, 0, coordx);
		al_draw_text(tex, palette[4], 500, 80, 0, labels);

		// make operations visible
		al_flip_display();
	}

	al_destroy_display(display);
}
