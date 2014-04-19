SRC = lib/src/

all : compile clean

compile : $(SRC)main.o
	gcc -o make_random_file.bin $(SRC)main.o

main.o : $(SRC)main.c
	gcc -c $(SRC)main.c

clean : 
	rm $(SRC)*.o
