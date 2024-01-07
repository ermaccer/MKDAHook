#include "core.h"
#include "..\ps2mem.h"

void _printf(char* format, ...)
{
	((void(*)(const char*, ...))0x2033A0)(format);
}

void render()
{
	((void(*)())0x123130)();
}

int get_game_state()
{
	return *(int*)0x40A008;
}

void init_fatality_world()
{
	((void(*)())0x2B3FD0)();
}

int get_game_tick()
{
	return *(int*)0x40A034;
}

void set_game_speed(float speed)
{
	patchFloat(0x40A01C, speed);
}
