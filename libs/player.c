#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "player.h"

int get_center(float xi, float xf){
	int approx_center = xi + (xf) / 2;

	return approx_center;
}

void rect_hitbox_draw(float xi, float yi, float xf, float yf, ALLEGRO_COLOR c){

	al_draw_filled_rectangle(
				xi,
				yi,
				xi + xf,
				yi + yf,
				c
			); 
}
void moving(const ALLEGRO_KEYBOARD_STATE * state, int *x, int *y, int dw, int dh, int k){
		
		bool in_rx = (*x) < (dw - 16);
		bool in_lx = (*x) > 7;
		bool in_uy = (*y) > 7;
		bool in_dy = (*y) < (dh - 16);

		if(al_key_down(state, ALLEGRO_KEY_LEFT) && (in_lx)) *x-=k; 	//LEFT
		if(al_key_down(state, ALLEGRO_KEY_RIGHT) && (in_rx)) *x+=k;	//RIGHT
		if(al_key_down(state, ALLEGRO_KEY_UP) && (in_uy)) *y-=k;	//UP
		if(al_key_down(state, ALLEGRO_KEY_DOWN) && (in_dy)) *y+=k;	//DOWN
}

int n = 0;
int s_coords[2][1000];

void init_s_coords(int max){
	for(int i = 0; i < max; i++){
		s_coords[0][i] = 0;
		s_coords[1][i] = 0;
	}
}

int (*get_s_coords(void))[1000]{
	int (*spointer)[1000] = s_coords;
	return spointer;
}

void shoot(int center, int y, int vel, const int max, bool *shooting){
	bool restart;

	int vel_s[1000];

	ALLEGRO_COLOR def = al_premul_rgba(255, 255, 255, 177);

	if(*shooting) s_coords[0][n] = y - 1;
	s_coords[1][n] = center;

	restart = n > max;
	//(restart) ? n = 0 : n++;
	if(restart) n = 0;

	for(int i = 0; i < max; i++){
		if(s_coords[0][i] <= 0 && s_coords[0][i] >= y){
			s_coords[0][i] = y;
			vel_s[i] = 0;
		}
		if (s_coords[0][i] < y) vel_s[i] = vel;

		s_coords[0][i] -= vel_s[i];

		al_draw_filled_rectangle(
					s_coords[1][i],
					s_coords[0][i],
					s_coords[1][i] + 5,
					s_coords[0][i] + 5,
					def
				);
	}

	*shooting = false;
	n++;
}
