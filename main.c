#include <termios.h>
#include <unistd.h>

#include "check.h"
#include "render.h"
#include "change.h"


char input()
{
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




int main()
{
	int a[4][4] = {0}, max_rec = 0;
	rando(a);
	rando(a);
        while (1)
	{
		field(a);
		char znak = input();
		switch(znak)
		{
			case 'w':
				zdvig_up(a);
		 		break;
		        case 's':
				zdvig_down(a);
				break;
			case 'a':
				zdvig_left(a);
				break;
			case 'd':
				zdvig_right(a);
				break;
		        case 'q':
				print_end((max(a) > max_rec? max(a) : max_rec));
				return 0;
		}   
		field_clear();
		rando(a);
		if (!creak)
		{
			print_end((max(a) > max_rec? max(a) : max_rec));
		        max_rec = (max(a) > max_rec? max(a) : max_rec);
			break;
		}
	}
	return 0;


}
