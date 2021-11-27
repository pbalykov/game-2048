#pragma once

#include <termios.h>
#include <unistd.h>
#include <stdio.h>


void printf_field(int **data, int len);
void cout_max_and_sum(int max, int sum);
void clear(int len);
void print(char* string);
char input(); 
