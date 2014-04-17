#Begin of Makefile

#Vars
SRC = lib/src/

#Compilation Logic
all : compile clear

compile : $(SRC)main.o $(SRC)stress_test.o $(SRC)parameter_checker.o
	gcc -o stress_test.bin $(SRC)main.o $(SRC)stress_test.o $(SRC)parameter_checker.o

main.o : $(SRC)main.c
	gcc -c $(SRC)main.c
	
stress_test.o : $(SRC)stress_test.c
	gcc -c $(SRC)stress_test.c
	
parameter_checker.o : $(SRC)parameter_checker.c
	gcc -c $(SRC)parameter_checker.c

clear :
	rm $(SRC)*.o

#End of Makefile
