#include <stdlib.h>
#include <time.h>

#include "work_field.h"
#include "iostream.h"
#include "check_field.h"



int main(){
	srand(time(NULL));
	int max = 0, len = 4, sum = 0;
	int** field = creat_field(len);
	char flag_sign;
	while (1){
		cout_max_and_sum((max = MAX(max_filed(field, len), max)) ,sum);
		printf_field(field, len);
		if (!check_moves(field, len) || max == 2048)
		{	
			free_field(field, len);
			clear(len + 3);
			print(max != 2048 ? "\t   \e[38;5;183;1mВаш результат\e[m" : "\t\e[38;5;183;1mПоздравляю вы выйграли\e[m");
			cout_max_and_sum(max, sum);
			print("\t\e[38;5;113;1mНажмите q чтобы выйти:\e[m");
			if (input() == 'q')
				return 0;

			field = creat_field(len);
			int max = 0, sum = 0;
			clear(4);
			continue;
		}
		do{
			char sign = input();
		       	flag_sign = 1;
			if (sign == 'a' || sign == 'A')
				sum += shift_left(field, len);
			else if (sign == 'd' || sign == 'D')
				sum += shift_right(field, len);
			else if (sign == 's' || sign == 'S')
				sum += shift_down(field, len);
			else if (sign == 'w' || sign == 'W')
				sum += shift_up(field, len);
			else if (sign == 'q')
				return 0;
			else
				flag_sign = 0;
		}while(!flag_sign);
		clear(len + 3);
	 	rand_field(field, len);
	}
	return 0;
}
		 
       		
	
	
	
