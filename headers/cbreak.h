#pragma once

#include <termios.h>
#include <unistd.h>


struct termios getcbreak();
void offcbreak();
void oncbreak();
