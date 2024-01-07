#pragma once
#include "core.h"

#define PLYR_OBJ 0x40A150
#define PLYR_PDATA 0x40A154
#define HIS_OBJ 0x40A14C
#define HIS_PDATA 0x40A148

#define P1_OBJ 0x40A104
#define P2_OBJ 0x40A108


void ani_to_frame_x(float frame);
void random_voice(int id);
void start_gore_meatchunks_shards(int obj, int boneID, CVector* vec, void* func, int unk);
void start_blood_explosion(int obj, int pdata, int boneID, CVector* vec, CVector* unk);
void snd_req(int id);
void start_gusher(void* func, int pdata, int obj, int boneID, CVector* unk, CVector* size);
void get_bone_world_pos(int obj, int boneID, CVector* pos);
void start_big_blood_pool(int id, CVector* pos, int pdata);