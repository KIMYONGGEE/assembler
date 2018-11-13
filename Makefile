myas: main.o check.o trans.o
	gcc -O myas main.o check.o trans.o -lm
main.0 : main.c
	gcc -o -Wall -c main.c
check.0 : check.c
	gcc -o -Wall -c check.c
trans.0 : trans.c
	gcc -o -Wall -c trans.c
clean: main.o check.o trans.o
	rm -f main.o check.o trans.o myas
