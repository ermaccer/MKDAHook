#pragma once

typedef struct {
	int quanchi_fatal;
	int widescreen_mode;
}SSETTINGS;


#ifndef  PS2_BUILD

enum
{
	MaxIniSize = 5000
};

extern char PluginData[MaxIniSize];

#endif // ! PS2_BUILD

extern SSETTINGS settings;


void init_settings();