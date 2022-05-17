#include <render.h>
#include <cbreak.h>
#include <sideEffects.h>
#include <sys/select.h>


void exitRetur(const int tmp){
	offcbreak();
	oncursor();
	printf("\n");
	exit(tmp != 0 ? 1 : 0);
}

void beginGame(const size_t len){
	offcursor();
	repeat(" ", len / 2 - 4);
	printf("\e[1;36mGame 2048\e[0m\n");
}

void printBar(const int max, const int score, const size_t len){
	tableRows("\u250C", "\u2500", "\u2510\n", len);
	printf("\u2502\e[38;5;208;1mScore:%*d\e[0m\u2502\n", len * 4 + len - 7, score);
	printf("\u2502\e[38;5;208;1mMax number:%*d\e[0m\u2502\n", len * 4 + len - 12, max);
	tableRows("\u2514", "\u2500", "\u2518\n", len);
}

void printBarEnd(const int max, const int score, const size_t len){
	tableRows("\u250C", "\u2500", "\u2510\n", len);
	printf("\u2502\e[38;5;208;1mScore:%*d\e[0m\u2502\n", len * 4 + len - 7, score);
	printf("\u2502");
	max == 2048 ? wing(len * 4 + len - 2) : gameOver(len * 4 + len - 2);
	printf("\u2502\n");
	printf("\u2502\e[38;5;208;1mMax number:%*d\e[0m\u2502\n", len * 4 + len - 12, max);
	tableRows("\u2514", "\u2500", "\u2518\n", len);
}

void printField(int** data, const size_t len){
	tableRows("\u250C", "\u252C", "\u2510\n", len);
	for (size_t i = 0; i < len; i++){
		for (size_t j = 0; j < len; j++){
			printf("\u2502");
			if (data[i][j])
				printf("\x1b[1;38;5;%sm%4d\x1b[0m", color(data[i][j]), data[i][j]);
			else 
				repeat(" ", 4); 
		}
		printf("\u2502\n");
		if (i + 1 != len)
			tableRows("\u251C", "\u253C", "\u2524\n", len);
	}
	tableRows("\u2514", "\u2534", "\u2518", len);
}

char exitOrRestart(){
	char locations = 0;
	while (1){
		button(locations);
		char symbol = input();
		if (upperrcase(symbol) == 'A')
			locations = (--locations % 2 + 2) % 2;
		else if (upperrcase(symbol) == 'D')
			locations = (++locations % 2 + 2) % 2;
		else if (symbol == '\n')
			return locations;
		printf(CLEAR);
		printf("\n");
	}
}

char input(){
	fflush(stdout);
	oncbreak();
	char symbol;
	read(0, &symbol, 1);
	if (symbol == 27){	
		fd_set x1, x2;
		FD_ZERO(&x1);
		FD_SET(0, &x1);
		FD_ZERO(&x2);
		struct timeval tm = {0, 5};
		if (select(1, &x1, &x2, &x2, &tm)){
			read(0, &symbol, 1);
			if (symbol == 91){
				read(0, &symbol, 1);
				if (symbol == 'A')
					symbol = 'W';
				else if (symbol == 'B')
					symbol = 'S';
				else if (symbol == 'C')
					symbol = 'D';
				else if (symbol == 'D')
					symbol = 'A';
			}
		}
	}
	offcbreak();
	return symbol;
}
