#pragma once
#include <stdio.h>


int lenNumber(int number);
char upperrcase(char number);
void oncursor();
void offcursor();
void tableRows(char* begin, char* assoc, char* end, size_t len);
char* color(int number);
void button(char  indications);
void repeat(const char* string, size_t len);
void gameOver(const int lenField);
void wing(const int lenField);
