#include "quanchi.h"
#include "..\mkda.h"

void quanchi_blood_gushing()
{
	int his_obj = *(int*)HIS_OBJ;
	int his_pdata = *(int*)HIS_PDATA;
	CVector gush_unk = { 0,0,0};
	CVector gush_size = { 0, 0.75f, 0 };
	ani_to_frame_x(225.0);

	start_gusher((void*)0x3DCEE0, his_pdata, his_obj, 9, &gush_unk, &gush_size);
}

void quanchi_blood_stretcher()
{
	int his_obj = *(int*)HIS_OBJ;
	int his_pdata = *(int*)HIS_PDATA;
	CVector pos = { 0.1f,0.1f,0.1f };
	CVector blood_vec = { 0.1f, 0.1, 0.1f };
	CVector blood_unk = { 0.05f, 0.05f, 0.05f };

	ani_to_frame_x(325.0);
	start_gore_meatchunks_shards(his_obj, 15, &pos, (void*)0x29C600, 0);
	start_blood_explosion(his_obj, his_pdata, 15, &blood_vec, &blood_unk);
	start_blood_explosion(his_obj, his_pdata, 16, &blood_vec, &blood_unk);
	*(char*)(*(int*)(his_obj + 64) + 3609) = *(char*)(*(int*)(his_obj + 64) + 3609) & 0xFE | 1; // this hides head

	ani_to_frame_x(335.0);
}
