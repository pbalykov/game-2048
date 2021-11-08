#include "check_field.h"

int MAX(int a, int b){
	return (a > b? a : b);
}

int max_filed(int** data, int len){
	int max = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			max = MAX(max, data[i][j]);
	return max;
}

int check_moves(int** data, int len){
	for (int i = 0; i < len; i++)
	{
		int vertical = -1, horizontal = -1;
		for (int j = 0; j < len; j++)
		{
			if ((data[i][j] == horizontal) || (data[j][i] == vertical) || 
			    !data[i][j]  || !data[j][i])
				return 1;

			if (data[i][j])
				horizontal = data[i][j];
			if (data[j][i])
				vertical = data[j][i];
		}
	}
	return 0;
}
