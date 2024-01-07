#include <stdio.h>
#include "ps2mem.h"
#include "mkda.h"
#include "fatality/quanchi.h"
#include "mkdahook.h"
#include "settings.h"

int CompatibleCRCList[] = { 0x59F35E8};


void init()
{
    init_settings();
    headDistance = 0.2f;
    _printf("MKDAHook init!\n");

    makeJal(0x11FB54, hook_render);
    Menu_Init();

    if (settings.quanchi_fatal)
    {
        makeJal(0x2D3D40, quanchi_blood_gushing);
        makeJal(0x2D3DD4, quanchi_blood_stretcher);
    }

    if (settings.widescreen_mode)
    {
        makeJal(0x180964, fov_hook);

        // ported from mkd
        static float newAr = ASPECT_OVERRIDE;
        patchShort(0x1809F8, *(short*)((int)&newAr + 2));
        patchShort(0x1809F8 + 4, *(short*)((int)&newAr));
    }
}

int main()
{
    return 0;
}
