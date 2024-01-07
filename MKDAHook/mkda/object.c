#include "object.h"

void get_matrix_right(int obj, CVector* mat)
{
	mat->x = *(float*)(*(int*)(obj + 28) + 16);
	mat->y = *(float*)(*(int*)(obj + 28) + 20);
	mat->z = *(float*)(*(int*)(obj + 28) + 24);
}

void get_matrix_forward(int obj, CVector* mat)
{
	mat->x = *(float*)(*(int*)(obj + 28) + 48);
	mat->y = *(float*)(*(int*)(obj + 28) + 52);
	mat->z = *(float*)(*(int*)(obj + 28) + 56);
}
