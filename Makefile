myas: main.o check.o trans.o
	gcc -o myas main.o check.o trans.o -lm
main.0 : main.c
	gcc -O -Wall -c main.c
check.0 : check.c
	gcc -O -Wall -c check.c
trans.0 : trans.c
	gcc -O -Wall -c trans.c
clean: 
	rm -f main.o check.o trans.o myas
