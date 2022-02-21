#pragma once
#include <shifts.h>


void creatField(int*** arrField, const int len);
void locatRand(int** arrField, const int len);
bool wingGame(int** arrField, const int len, int* max);
void freeField(int** arrField, const int len);
