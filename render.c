#include "render.h"

void field(int arr[][4])
{
	for (int i = 0; i < 4; i++)
	{
		printf("|");
		for (int j = 0; j < 4; j++)
			printf("%4d ", arr[i][j]);
		printf("|\n");
	}
}


void field_clear()
{
	for (int i = 0; i < 4; i++)
		printf("\x1b[A\33[2K\r");
}

void print_end(int max_rec)
{
	printf("Ваш рекорд в этой парти, %d\n" ,max_rec);
}
