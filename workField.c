#include <workField.h>
#include <stdlib.h>


#define MAX(a, b) a > b? a : b;


void creatField(int*** arrField, const int len){
	*arrField = malloc(sizeof(int*) * len);
	for (int i = 0; i < len; i++)
		arrField[0][i] = calloc(len, sizeof(int)); 
	locatRand(*arrField, len);
	locatRand(*arrField, len);
}

void locatRand(int** arrField, const int len){
       typedef struct{int first; int second;}pair;
       pair* arrEmpty = NULL;
       int lenEmpty = 0;
       for (int i = 0; i < len; i++)
	      for (int j = 0; j < len; j++)
		      if (!arrField[i][j]){
			      arrEmpty = realloc(arrEmpty, sizeof(pair) * ++lenEmpty);
			      *(arrEmpty + lenEmpty - 1) = (pair){i, j};
		      }
       if (lenEmpty){
	       pair tmp = *(arrEmpty + rand() % lenEmpty);
	       arrField[tmp.first][tmp.second] = 2;
       } 
       free(arrEmpty);
}
	
void freeField(int** arrField, const int len){
	for (int i = 0; i < len; i++)
		free(arrField[i]);
	free(arrField);
}


bool wingGame(int** arrField, const int len, int* max){
	bool endGame = false; 
	for (int i = 0; i < len; i++){
		int gap = 0;
		for (int j = 0; j < len; j++){
			if ( arrField[i][j] == gap || !arrField[i][j])
				endGame = true;
			gap = arrField[i][j] ? arrField[i][j] : gap;
			*max = MAX(*max, arrField[i][j]); 
		}
	}
	return !endGame;
}
