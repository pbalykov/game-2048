.PHONY: all clear run

all: main

main: main.o workField.o shifts.o render.o cbreak.o sideEffects.o
	gcc $^ -o Game-2048 

%.o: %.c
	gcc -Iheaders -c $< -o $*.o

clean:
	rm -f *.o Game-2048

run:main 
	./Game-2048
