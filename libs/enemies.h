#ifndef ENEMIES_H
#define ENEMIES_H

void draw_enemy_hitbox(int x, int y);
int get_enemy_center(int x, int xf);

void enemy_collision(const int a_size, int (*shoots)[a_size], int x, int y, int *score);

/*
int * get_eshoots_array();
void init_e_coords(int e, int s);
void enemy_shoot(int e_d, int center, int y, float funcx, float funcy, float velfac_x, float velfac_y, const int max, bool *eshooting);
*/

#endif
