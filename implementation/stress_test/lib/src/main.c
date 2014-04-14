#include <stdio.h>
#include <stdlib.h>
#include "struct.c"
#include "../stress_test.h"

int main(int argc, char ** argv){

	int long long num_instructions; // Passed by parameter - Defines how many instruction will be executed
	int long long num_cicles; // Passed by parameter - Defines the number of executions
	boolean debug; // Passed by Parameter - Defines if the program will print cicles time result
	
	// Init TO REMOVE - Those variables are just for test the application
		debug = TRUE;
		num_instructions = 100000000;
		num_cicles = 400;
	// End TO REMOVE

	execute_stress_test(num_instructions, num_cicles, debug);

	return 0;

}
