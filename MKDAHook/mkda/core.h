#pragma once

typedef struct {
	float x, y, z;
}CVector;

void _printf(char* format, ...);
void render();

enum game_state {
	STATE_SELECT = 2,
	STATE_MENU = 11,
	STATE_GAME = 5
};

int get_game_state();
void init_fatality_world();
int get_game_tick();

void set_game_speed(float speed);