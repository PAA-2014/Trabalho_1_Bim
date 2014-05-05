#Begin Makefile

#Vars
SRC = lib/src/

#Compilation Logic
all : compile clear

compile : $(SRC)main.o $(SRC)bin_tree.o $(SRC)parameter_checker.o $(SRC)file.o $(SRC)util.o $(SRC)debug.o $(SRC)struct.o
	gcc -o bin_tree_with_count.bin $(SRC)main.o $(SRC)bin_tree.o $(SRC)parameter_checker.o $(SRC)file.o $(SRC)util.o $(SRC)debug.o $(SRC)struct.o

clear : 
	rm $(SRC)*.o

debug.o : $(SRC)debug.c
	gcc -c $(SRC)debug.c
	
util.o : $(SRC)util.c
	gcc -c $(SRC)util.c

file.o : $(SRC)file.c
	gcc -c $(SRC)file.c

parameter_checker.o : $(SRC)parameter_checker.c
	gcc -c $(SRC)parameter_checker.c

main.o : $(SRC)main.c
	gcc -c $(SRC)main.c

bin_tree.o : $(SRC)bin_tree.c
	gcc -c $(SRC)bin_tree.c

struct.o : $(SRC)struct.c
	gcc -c $(SRC)struct.c

#End Makefile
