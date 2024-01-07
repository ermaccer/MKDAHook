#include "camera.h"

void set_cam_position(CVector* pos)
{
	((void(*)(CVector*))0x17F380)(pos);
}

void set_cam_rotation(CVector* rot)
{
	((void(*)(CVector*))0x17F340)(rot);
}

void set_cam_target(CVector* target)
{
	((void(*)(CVector*))0x17F240)(target);
}
