.PHONY: all clear run

all: main

main: main.o work_field.o iostream.o check_field.o
	gcc *.o -o Game_2048 

%.o: %.c
	gcc -c $< -o $*.o

clean:
	rm -f *.o Game_2048

run:main 
	./Game_2048
