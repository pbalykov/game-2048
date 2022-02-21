#include <sideEffects.h>
#include <stdio.h>


int lenNumber(int number){
	int k = 0;
	while (++k && (number /= 10));
	return k;
}

char upperrcase(char sumbol){
	return  'a' <= sumbol && sumbol <= 'z' ?  sumbol - 'a' + 'A' : sumbol;
}

void oncursor(){
	printf("\x1b[?25h");
}

void offcursor(){
	printf("\x1b[?25l");
}

void tableRows(char* begin, char* assoc, char* end, size_t len){
	printf("%s", begin);
	do{
		repeat("\u2500", 4);
		printf("%s", len - 1 != 0 ? assoc : end);
	}while(--len);
}

char* color(int number){
	char* colors[] = {"11", "214", "202", "196", "199", "164", "91", "93", "69", "21"};
	int k = 0;
	for (int i = 1; i != number; i *= 2, k++);
	return colors[k - 1];
}

void button(char locations){ 
	printf(" %sNew game\e[0m", !(locations % 2) ? "\e[7;1;31;15m" : "\e[1m");
	repeat(" ", 6);
       	printf("%squit!\e[0m", (locations % 2) ? "\e[7;1;31;15m" : "\e[1m");
}

void repeat(const char* string, size_t len){
	while (len-- && printf("%s", string));
}



