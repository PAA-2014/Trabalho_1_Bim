all : compile clear

compile : main.o bin_tree.o struct.o
	gcc -o bin_tree main.o bin_tree.o struct.o

clear : 
	rm *.o

main.o : main.c
	gcc -c main.c

bin_tree.o : bin_tree.c
	gcc -c bin_tree.c

struct.o : struct.c
	gcc -c struct.c
