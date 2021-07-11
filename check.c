#include "check.h"


int creak(int a[][4])
{
	for (int i = 0; i < 3; i++)
		for(int  j = 0; j < 3; j++)
			if(a[i][j + 1] == a[i][j] && a[j][i] == a[j + 1][i])
				return 1;
	return 0;
}


int max(int a[][4])
{
	int max = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if(a[i][j] > max)
				max = a[i][j];
	return max;
}
