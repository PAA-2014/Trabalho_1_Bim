#Begin of Makefile

#Vars
SRC = lib/src/

#Compilation Logic
all : compile clear

compile : $(SRC)main.o $(SRC)stress_test.o
	gcc -o calib.bin $(SRC)main.o $(SRC)stress_test.o

main.o : $(SRC)main.c
	gcc -c $(SRC)main.c
	
stress_test.o : $(SRC)stress_test.c
	gcc -c $(SRC)stress_test.c

clear :
	rm $(SRC)*.o

#End of Makefile
