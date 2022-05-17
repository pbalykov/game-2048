#include <signal.h>
#include <time.h>
#include <render.h>
#include <workField.h>


int main(){
	signal(SIGINT, exitRetur);
	srand(time(NULL));
	const int LEN = 4;
	bool game = true;
	int** field = NULL;
	creatField(&field, LEN);
	beginGame(LEN * 4 + LEN + 1);
	int sum = 0, max = 2;
	while (game){
		bool motion = false;
		if (wingGame(field, LEN, &max)){
			printBarEnd(max, sum, LEN); 
			freeField(field, LEN);
			if (exitOrRestart())
				exitRetur(0);
			creatField(&field, LEN);
			sum = 0; 
			max = 2;
			repeat(CLEAR, LEN + 1);
		}
		printBar(max, sum, LEN); 
		printField(field, LEN);
		do{
			char symbol = input();
			if (upperrcase(symbol) == 'A')
				motion = shiftsLeft(field, LEN, &sum);
			else if (upperrcase(symbol) == 'D')
				motion = shiftsRight(field, LEN, &sum);
			else if (upperrcase(symbol) == 'W')
				motion = shiftsUp(field, LEN, &sum);
			else if (upperrcase(symbol) == 'S')
				motion = shiftsDown(field, LEN, &sum);
			else if (symbol == 'q'){
				freeField(field, LEN);
				exitRetur(0);
			}
		}while(!motion);
		locatRand(field, LEN);
		repeat(CLEAR, LEN + LEN + LEN);
	}
	return 0;
}
