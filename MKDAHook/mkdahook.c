#include "mkdahook.h"
#include "inf.h"
float headDistance = 0.2;
CVector camPos;
CVector camRot;
int freeCamera = 0;
int hook_timer = 0;
int m_bFreezeWorld = 0;

void hook_render()
{
	process_mkdahook();
	render();
}

void process_mkdahook()
{
	if (get_game_state() == STATE_GAME)
	{
		//process_firstperson_cam();

		if (GetAsyncKeyState(72))
			Menu_Toggle_FreezeWorld();

		if (GetAsyncKeyState(70))
			init_fatality_world();

		if (GetAsyncKeyState(71))
			Menu_ToggleFreeCam();

		Menu_ProcessFreeCamera();
	}

}

void process_firstperson_cam()
{
	int p1_obj = *(int*)P1_OBJ;
	int p2_obj = *(int*)P2_OBJ;

	if (p1_obj && p2_obj)
	{
		CVector headPos;
		CVector targetPos;
		CVector forwardMat;
		get_bone_world_pos(p1_obj, 16, &headPos);
		get_bone_world_pos(p2_obj, 16, &targetPos);
		get_matrix_forward(p1_obj, &forwardMat);

		headPos.x += forwardMat.x * headDistance;
		headPos.y += forwardMat.y * headDistance;
		headPos.z += forwardMat.z * headDistance;

		set_cam_position(&headPos);
		set_cam_target(&targetPos);
	}
}

void Menu_ToggleFreeCam()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	freeCamera = !freeCamera;
}

void Menu_ProcessFreeCamera()
{
	int camera = *(int*)0x40A518;
	if (freeCamera)
	{
		if (camera)
		{
			static float camSpeed = 0.15f;

			CVector plrPos;
			CVector rightMat;
			CVector forwardMat;
			get_matrix_right(camera, &rightMat);
			get_matrix_forward(camera, &forwardMat);

			if (GetAsyncKeyState(90))
				camSpeed = 0.035f;
			else
				camSpeed = 0.15f;

			if (GetAsyncKeyState(87))
			{
				camPos.x += camSpeed * forwardMat.x;
				camPos.y += camSpeed * forwardMat.y;
				camPos.z += camSpeed * forwardMat.z;
			}

			if (GetAsyncKeyState(83))
			{
				camPos.x -= camSpeed * forwardMat.x;
				camPos.y -= camSpeed * forwardMat.y;
				camPos.z -= camSpeed * forwardMat.z;
			}
			if (GetAsyncKeyState(65))
			{
				camPos.x += camSpeed * rightMat.x;
				camPos.y += camSpeed * rightMat.y;
				camPos.z += camSpeed * rightMat.z;
			}
			if (GetAsyncKeyState(68))
			{
				camPos.x -= camSpeed * rightMat.x;
				camPos.y -= camSpeed * rightMat.y;
				camPos.z -= camSpeed * rightMat.z;
			}
			if (GetAsyncKeyState(81))
				camPos.y += camSpeed;
			if (GetAsyncKeyState(69))
				camPos.y -= camSpeed;

			if (GetAsyncKeyState(37))
				camRot.y += camSpeed / 4.0f;
			if (GetAsyncKeyState(39))
				camRot.y -= camSpeed / 4.0f;

			if (GetAsyncKeyState(38))
				camRot.x -= camSpeed / 4.0f;
			if (GetAsyncKeyState(40))
				camRot.x += camSpeed / 4.0f;

			if (GetAsyncKeyState(88))
				camRot.z -= camSpeed / 4.0f;
			if (GetAsyncKeyState(67))
				camRot.z += camSpeed / 4.0f;

			set_cam_position(&camPos);
			set_cam_rotation(&camRot);

		}
	}
	else
	{
		if (camera)
		{
			camPos = *(CVector*)(camera + 144);
			camRot = *(CVector*)(camera + 176);
		}

	}
}

void Menu_Toggle_FreezeWorld()
{
	if (get_game_tick() - hook_timer <= 15) return;
	hook_timer = get_game_tick();
	m_bFreezeWorld = !m_bFreezeWorld;

	if (m_bFreezeWorld)
		set_game_speed(0.0f);
	else
		set_game_speed(1.0f);
}

void Menu_Init()
{
	freeCamera = 0;
	m_bFreezeWorld = 0;
	hook_timer = get_game_tick();
}

// ported from mkd
float fov_hook(float val)
{
	val = (3.14f * FOV_OVERRIDE) / 360.0f;
	float result = ((float(*)(float))0x2D1880)(val);
	return result;
}