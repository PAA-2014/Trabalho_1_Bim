#Begin Makefile

#Vars
SRC = lib/src/

#Compilation Logic
all : compile clear

compile : $(SRC)main.o $(SRC)bin_tree.o $(SRC)struct.o
	gcc -o bin_tree.bin $(SRC)main.o $(SRC)bin_tree.o $(SRC)struct.o

clear : 
	rm $(SRC)*.o

main.o : $(SRC)main.c
	gcc -c $(SRC)main.c

bin_tree.o : $(SRC)bin_tree.c
	gcc -c $(SRC)bin_tree.c

struct.o : $(SRC)struct.c
	gcc -c $(SRC)struct.c

#End Makefile
