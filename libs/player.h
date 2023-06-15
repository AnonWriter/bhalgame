#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>

int get_center(float xi, float xf);

void rect_hitbox_draw(float xi, float yi, float xf, float yf, ALLEGRO_COLOR);
void moving(const ALLEGRO_KEYBOARD_STATE * state, int *x, int *y, int dw, int dh, int k);

void shoot(int center, int y, int vel, int max, bool *shooting);
void init_s_coords(int max);

#endif
