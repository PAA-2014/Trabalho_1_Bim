#Begin of Makefile

#Vars
SRC = src/

#Compilation Logic
all : compile clear

compile : $(SRC)main.o
	gcc -o calib.bin $(SRC)main.o

main.o : $(SRC)main.c
	gcc -c $(SRC)main.c

clear :
	rm $(SRC)*.o

#End of Makefile
