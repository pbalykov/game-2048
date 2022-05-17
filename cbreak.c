#include <cbreak.h>


struct termios getcbreak(){
	struct termios values;
	tcgetattr(0, &values);
	return values;
}

void oncbreak(){
	struct termios values = getcbreak();
	values.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &values);
}

void offcbreak(){
	struct termios values = getcbreak();
	values.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &values);
}
