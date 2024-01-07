#include "settings.h"
#include "pcsx2/inireader.h"
#include "mkda.h"

SSETTINGS settings = {};
#ifndef  PS2_BUILD
char PluginData[MaxIniSize] = { 1 };
#endif
void init_settings()
{
#ifndef  PS2_BUILD
	inireader.SetIniPath((char*)PluginData + sizeof(unsigned int), *(unsigned int*)PluginData);

	settings.quanchi_fatal = inireader.ReadInteger("Settings", "NewQuanChiFatality", 0);
	settings.widescreen_mode = inireader.ReadInteger("Settings", "Widescreen", 0);

	_printf("Settings read!\n");
#else
	settings.no_intro = 0;
	settings.blaze_enable_fatalities = 0;
#endif
}
