#include "script.h"

void ani_to_frame_x(float frame)
{
	((void(*)(float))0x20F000)(frame);
}

void random_voice(int id)
{
	((void(*)(int))0x128BC0)(id);
}

void start_gore_meatchunks_shards(int obj, int boneID, CVector* vec, void* func, int unk)
{
	((void(*)(int, int, CVector*, void*, int))0x2BA0B0)(obj, boneID, vec, func, unk);
}

void start_blood_explosion(int obj, int pdata, int boneID, CVector* vec, CVector* unk)
{
	((void(*)(int, int, int, CVector*, CVector*))0x29BF60)(obj, pdata, boneID, vec, unk);
}

void snd_req(int id)
{
	((void(*)(int))0x128800)(id);
}

void start_gusher(void* func, int pdata, int obj, int boneID, CVector* unk, CVector* size)
{
	((void(*)(void*, int, int, int, CVector*, CVector*))0x2E2A10)(func, pdata, obj, boneID, unk, size);
}

void get_bone_world_pos(int obj, int boneID, CVector* pos)
{
	((void(*)(int, int, CVector*))0x132940)(obj, boneID, pos);
}

void start_big_blood_pool(int id, CVector* pos, int pdata)
{
	((void(*)(int, CVector*, int))0x2BB930)(id, pos, pdata);
}
