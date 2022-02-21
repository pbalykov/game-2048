#include <shifts.h>


bool shiftsLeft(int** arrField, const int len, int* sum){
	bool changesField = false;
	for (int i = 0; i < len; i++){
		bool comparisons = false;
		int changes = 0;
		for(int j = 0; j < len; j++)
			if (*(*(arrField + i) + j)){
				if (comparisons && arrField[i][changes - 1] == arrField[i][j]){
					comparisons = false;
					arrField[i][changes - 1] *= 2;
					*sum += arrField[i][changes - 1];
				}
				else{
					comparisons = true;
					arrField[i][changes++] = arrField[i][j];
				}
				changesField = j != changes - 1 ? true : changesField;
			}
		for ( ; changes < len; )
		       arrField[i][changes++] = 0;
	}
	return changesField;
}


bool shiftsRight(int** arrField, const int len, int* sum){
	bool changesField = false;
	for (int i = 0; i < len; i++){
		bool comparisons = false;
		int changes = len - 1;
		for (int j = len - 1 ; j >= 0; j--)
			if(arrField[i][j]){
				if (comparisons && arrField[i][changes + 1] == arrField[i][j]){
					comparisons = false;
					arrField[i][changes + 1] *= 2;
					*sum += arrField[i][changes + 1];
				}
				else{
					comparisons = true;
					arrField[i][changes--] = arrField[i][j];
				}
				changesField = j != changes + 1 ? true : changesField;
			}
		for ( ; changes > -1; )
			arrField[i][changes--] = 0;
	}
	return changesField;
}

bool shiftsUp(int** arrField, const int len, int* sum){
	bool changesField = false;
	for (int i = 0; i < len; i++){
		bool comparisons = false;
		int changes = 0;
		for (int j = 0; j < len; j++)
			if (arrField[j][i]){
				if (comparisons && arrField[changes - 1][i] == arrField[j][i]){
					comparisons = false;
					arrField[changes - 1][i]*= 2;
					*sum += arrField[changes - 1][i];
				}
				else{
					comparisons = true;
					arrField[changes++][i] = arrField[j][i];
				}
				changesField = j != changes - 1 ? true : changesField;
			}
		for ( ; changes < len; )
			arrField[changes++][i] = 0;
	}
	return changesField;
}	
					
bool shiftsDown(int** arrField, const int len, int* sum){
	bool changesField = false;
	for (int i = 0; i < len; i++){
	 	bool comparisons = false;
		int changes = len - 1;
		for (int j = len - 1; j >= 0; j--)
			if (arrField[j][i]){
				if(comparisons && arrField[j][i] == arrField[changes + 1][i]){
					comparisons = false;
					arrField[changes + 1][i] *= 2;
					*sum += arrField[changes + 1][i]; 
				}
				else{
					comparisons = true;
					arrField[changes--][i] = arrField[j][i];
				}
				changesField = j != changes + 1 ? true : changesField;
			}
		for ( ; changes >= 0; )
			arrField[changes--][i] = 0;
	}
	return changesField; 
}
