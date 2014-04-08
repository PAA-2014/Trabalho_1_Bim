all : compile clear

compile : main.o
	gcc -o bin_calib main.o

main.o : main.c
	gcc -c main.c

clear :
	rm *.o
