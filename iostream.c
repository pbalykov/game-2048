#include "iostream.h"

void margins(char* symbol, int len, char* last_symbol){
	for (int i = 0; i < len; i++)
		printf("%s", symbol);
	printf("%s", last_symbol);
	return;
}


int len(int number){
	int i = 0;
	for (i; number; i++)	
		number /= 10;
	return i;
}


void center(int number){
	 int s = len(number);
	 margins(" ", (4 - s) / 2, "");
	 printf("%d", number);
	 margins(" ", (4 - s) / 2 + (4 - s) % 2, "");
	 return;
}



void cout_max_and_sum(int number, int sum){
	printf("\e[38;5;208;1mMax values = %d\e[m", number);
	margins(" ", 4 - len(number) + 7, "");
	printf("\e[1;31mAmount = %d\n\e[m", sum);
	return;
}

void printf_field(int **data, int len){
	margins(" ", 8, "");
	margins("_", 21, "\n");
	for (int i = 0; i < len; i++)
	{
		margins(" ", 8, "");
		for (int j = 0; j < len; j++)
		{
			printf("|");
			if (data[i][j])
			 	center(data[i][j]);
			else
				margins(" ", 4, "");
		}
		printf("|\n");
	}
	margins(" ", 8, "");
	margins("¯", 21, "\n");
	return ;
}

char input(){
	char znak;
	struct termios inp = {0}; 
	tcgetattr(0, &inp);
	inp.c_lflag &= ~ICANON;
	inp.c_lflag &= ~ECHO;
	inp.c_cc[VMIN] = 1;
	inp.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &inp);
	read(0, &znak, 1);
	inp.c_lflag |= ICANON;
	inp.c_lflag |= ECHO;
	tcsetattr(0, TCSADRAIN, &inp);
	return znak;
}


void clear(int len){
	for (int i = 0; i < len; i++)
		printf("\x1b[A\33[2K\r");
}
			
void print(char* string){
	printf("%s\n", string);
	return;
}
