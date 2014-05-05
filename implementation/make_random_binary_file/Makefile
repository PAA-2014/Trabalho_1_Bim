SRC = lib/src/

all : compile clean

compile : $(SRC)main.o $(SRC)make_random_binary_file.o $(SRC)file.c $(SRC)parameter_checker.o $(SRC)util.o $(SRC)debug.o
	gcc -o make_random_binary_file.bin $(SRC)main.o $(SRC)make_random_binary_file.o $(SRC)file.c $(SRC)parameter_checker.o $(SRC)util.o $(SRC)debug.o

file.o : $(SRC)file.c
	gcc -c $(SRC)file.c

make_random_binary_file.o : $(SRC)make_random_binary_file.c
	gcc -c $(SRC)make_random_binary_file.c

parameter_checker.o : $(SRC)parameter_checker.c
	gcc -c $(SRC)parameter_checker.c

util.o : $(SRC)util.c
	gcc -c $(SRC)util.c

debug.o : $(SRC)debug.c
	gcc -c $(SRC)debug.c

main.o : $(SRC)main.c
	gcc -c $(SRC)main.c

clean : 
	rm $(SRC)*.o
