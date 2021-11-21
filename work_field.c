#include  "work_field.h"

int** creat_field(int len){
	int **data = (int**) malloc (sizeof(int*) * len);
	
	for (int i = 0; i < len; i++)
		data[i] = (int*) calloc (len, sizeof(int));
	
	rand_field(data, len);
	rand_field(data, len);
	return data;
}

void free_field(int** data, int len){
	for (int i = 0; i < len; i++)
		free(data[i]);
	free(data);
}

int rand_field(int** data, int len){
	struct pair values_rand = {-1, -1};
	int n = 0;
        struct pair *arr = (struct pair*) malloc (n * sizeof(struct pair));
	for (int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			if (!data[i][j]){
				arr = (struct pair*) realloc(arr, (n + 1)  * sizeof(struct pair));
				arr[n++] = (struct pair){i, j};
			}
	
	if (n){
		values_rand = arr[rand() % n];
		data[values_rand.first][values_rand.second] = 2;
		return 1;
	}	
	free(arr);
	return 0;
}

int shift_left(int** data, int len){
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		int ij = 0, flag_changes = 0;
		for (int j = 0; j < len; j++)
			if (data[i][j])
			     	if (flag_changes && data[i][j] == data[i][ij - 1])
				{
					data[i][ij - 1] *= 2;
					sum += data[i][ij - 1];
			        	flag_changes = 0;
				}
				else
				{
					data[i][ij++] = data[i][j];
					flag_changes = 1;
				} 

		for(ij; ij < len; ij++)
			data[i][ij] = 0;
	}
	return sum;
}

int shift_right(int** data, int len){
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		int ij = len - 1, flag_changes = 0;
		for (int j = len - 1; j >= 0; j--)
			if (data[i][j])
			     	if (flag_changes && data[i][j] == data[i][ij + 1])
				{
					data[i][ij + 1] *= 2;
					sum += data[i][ij + 1];
			        	flag_changes = 0;
				}
				else
				{
					data[i][ij--] = data[i][j];
					flag_changes = 1;
				} 

		for(int j = 0; j <= ij; j++)
			data[i][j] = 0;
	}
	return sum;
}


int  shift_up(int** data, int len){
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		int ij = 0, flag_changes = 0;
		for (int j = 0; j < len; j++)
			if (data[j][i])
			     	if (flag_changes && data[j][i] == data[ij - 1][i])
				{
					data[ij - 1][i] *= 2;
					sum += data[ij - 1][i];
			        	flag_changes = 0;
				}
				else
				{
					data[ij++][i] = data[j][i];
					flag_changes = 1;
				} 

		for(ij; ij < len; ij++)
			data[ij][i] = 0;
	}
	return sum;
}

int shift_down(int** data, int len){
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		int ij = len - 1, flag_changes = 0;
		for (int j = len - 1; j >= 0; j--)
			if (data[j][i])
			     	if (flag_changes && data[j][i] == data[ij + 1][i])
				{
					data[ij + 1][i] *= 2;
					sum += data[ij + 1][i];
			        	flag_changes = 0;
				}
				else
				{
					data[ij--][i] = data[j][i];
					flag_changes = 1;
				} 

		for(int j = 0; j <= ij; j++)
			data[j][i] = 0;
	}
	return sum;
}
