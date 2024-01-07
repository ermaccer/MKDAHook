#pragma once
#include "mkda.h"
#define FOV_OVERRIDE 80.0f
#define ASPECT_OVERRIDE (16.0f / 9.0f)
extern float headDistance;

void hook_render();
void process_mkdahook();
void process_firstperson_cam();
void Menu_ToggleFreeCam();
void Menu_ProcessFreeCamera();
void Menu_Toggle_FreezeWorld();
void Menu_Init();

float fov_hook(float val);
