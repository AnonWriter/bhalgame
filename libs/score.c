#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int score = 0;

void init_score(){
	al_init_ttf_addon();
	al_init_font_addon();
	score = 0;
}

void draw_score(int sum){
	//char *s;
	score += sum;

	ALLEGRO_COLOR def = al_premul_rgba(255, 255, 255, 255);
	ALLEGRO_FONT * tex = al_load_ttf_font("../fonts/cmunci.ttf", 24, 0);

	//sprintf(s, "%d", score);
	al_draw_text(tex, def, 100, 30, 0, "hola");
}
