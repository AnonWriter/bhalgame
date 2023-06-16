#ifndef BULLETUTILS_H
#define BULLETUTILS_H

void init_bullets();
int (*get_bullets_coords_array(void))[1000];

void enemy_shooting();
bool player_collision();

#endif
