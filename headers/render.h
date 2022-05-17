#pragma once
#include <stdlib.h>


#define CLEAR "\r\33[2K\x1b[A"



void exitRetur(const int tmp);
void repeat(const char* string, size_t len);
void printBar(const int max, const int sckore, const size_t len);
void printBarEnd(const int max, const int sckore, const size_t len);
void beginGame(const size_t len);
void printField(int** arrField, const size_t len);
char input();
char upperrcase(char symbol);
char exitOrRestart();
