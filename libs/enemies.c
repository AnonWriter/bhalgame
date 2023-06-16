#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "enemies.h"

void draw_enemy_hitbox(int x, int y){
	ALLEGRO_COLOR def = al_premul_rgba(255, 255, 0, 177);

	al_draw_filled_rectangle(
				x,
				y,
				x + 30,
				y + 30,
				def
			);
}

int get_enemy_center(int x, int xf){
	int approx_center = x + (xf/2);
	return approx_center;
}

int sfactor = 0;
void enemy_collision(const int a_size, int (*shoots)[1000], int x, int y, int *score){

	bool within_x;
	bool within_y;

	for(int i = 0; i < a_size; i++){
		within_x = shoots[1][i] >= x && (shoots[1][i] + 5) <= x + 30;
		within_y = shoots[0][i] >= y && (shoots[0][i] + 5) <= y + 30;
		if(within_x && within_y){
			//printf("collision in %d at cycle %d\n", shoots[0][i], i);
			(*score)++;
		}
	}
}

/*
int e_coords[100][2][1000];
int m = 0;

void init_e_coords(int e,int s){
	for(int i = 0; i < s; i++){
		e_coords[i][0][i] = 0;
		e_coords[i][0][i] = 0;
	}
}


void enemy_shoot(int e_d, int center, int y, float funcx, float funcy, float velfac_x, float velfac_y, const int max, bool *eshooting){
	bool restart;

	//int components[2][1000];
	
	//
	ALLEGRO_COLOR def = al_premul_rgba(255, 255, 0, 177);
	//if(*eshooting) e_coords[e_d][0][n] = y + 1;
	e_coords[e_d][1][m] = y - 10;
	e_coords[e_d][1][m] = center;

	restart = m > max;
	if(restart) m = 0;

	for(int i = 0; i < max; i++){
		if (e_coords[e_d][0][i] >= 640) e_coords[e_d][0][i] = y - 10;

		if(e_coords[e_d][0][i] > y) e_coords[e_d][0][i] = funcx * velfac_y;
		e_coords[e_d][1][i] = funcx * velfac_x;

		al_draw_filled_circle(
					e_coords[e_d][1][i],
					e_coords[e_d][0][i],
					5,
					def
				);
	}

	m++;

}
*/
