#include <stdio.h>
#include <stdlib.h>
#include "struct.c"
#include "../stress_test.h"

int long long num_instructions; // Passed by parameter - Defines how many instruction will be executed
int long long num_cicles; // Passed by parameter - Defines the number of executions
boolean debug; // Passed by Parameter - Defines if the program will print cicles time result

boolean check_parameter(int argc, char ** argv);

int main(int argc, char ** argv){

	if(!check_parameter(argc, argv)){
		printf("ERRO : INVALID PARAMETERS\n\n");
		return -1;
	}

	execute_stress_test(num_instructions, num_cicles, debug);

	return 0;

}

boolean check_parameter(int argc, char ** argv){
	int actual_position;

	if(argc <= 1)
		return FALSE;
		
	for(actual_position=1; actual_position<argc; actual_position++) {
		if( strcmp(argv[actual_position],"-i") == 0 ){
			num_instructions = atoi(argv[actual_position+1]);
			actual_position ++;
		} else if( strcmp(argv[actual_position],"-c") == 0 ) {
			num_cicles = atoi(argv[actual_position+1]);
			actual_position ++;
		} else if( strcmp(argv[actual_position],"-d") == 0 )	
			debug = TRUE;
		else
			return FALSE;
	}
		
	return TRUE;
	
}
