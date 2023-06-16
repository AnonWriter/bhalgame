#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int bullet_coords[2][1000];

void init_bullets(const int max){
	for(int i = 0; i < max; i++){
		bullet_coords[0][i] = 0;
		bullet_coords[1][i] = 0;
	}
}
int (*get_bullets_coords_array(void))[1000]{
	int (*bpointer)[1000] = bullet_coords;
	return bpointer;
}

void enemy_shooting(){
}

bool player_collision(){
	bool player_hit;
	return player_hit;
}

