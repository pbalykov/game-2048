#pragma onse

#include <stdlib.h>
#include <stdio.h>

struct pair
{
	int first;
	int second;
};



int** creat_field(int len); 
void free(int** data, int len);
int rand_field(int** data, int len);
int shift_left(int** data, int len);
int shift_right(int** data, int len);
int shift_up(int** data, int len);
int shift_down(int** data, int len);
