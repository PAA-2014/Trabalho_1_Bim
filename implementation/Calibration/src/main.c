#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "struct.c"

// Define the boolean type
typedef enum enm_boolean {
FALSE, TRUE
} boolean;

int num_instructions; // Passed by parameter - Defines how much instruction will be executed
int num_cicles; // Passed by parameter - Defines the number of executions
boolean debug; // Passed by Parameter - Defines if the program will print cicles time results

/**
Check Parameters
Function that validates the parameters passed by the user at the call of program
*/
boolean check_parameters(int argc, char ** argv);

int to_int(char * string);

int main(int argc, char ** argv){

	debug = TRUE;
	num_instructions = 1000000000;
	num_cicles = 4;

	// Vars
	int i,aux_num_instructions;
	double total_time = 0, avarage_time;
	cicle ** cicles = (cicle **) malloc(sizeof(cicle*)*num_cicles);

	// Logic
	for(i=0;i<num_cicles;i++){
		cicles[i] = (cicle *) malloc(sizeof(cicle)*1);

		aux_num_instructions = num_instructions;

		cicles[i]->start = clock();
		while(aux_num_instructions--);
		cicles[i]->end = clock();

		// Calculate the time_spent
		cicles[i]->time_spent= (cicles[i]->end- cicles[i]->start / (double)CLOCKS_PER_SEC);
		total_time += cicles[i]->time_spent;

		// If the user wants to see the time per cicle
		if(debug)
			printf("Cicle_%d : %f seconds\n",i,cicles[i]->time_spent);
	}

	// Calculate the number of instructions
	avarage_time = total_time/num_cicles;

	// Print the Results
	printf("\n################### Results ###################\n\n");
	printf("Avarage Time : %f\n",avarage_time);
	printf("Instructions Per Second : %f\n",num_instructions/avarage_time);

	// Just to do not confuse with the console's prints
	printf("\n");

	return 0;
}

boolean check_parameters(int argc, char ** argv){

	int i;

	while(i<argc){

		if(!strcmp(argv[i],"-d")){
			debug = TRUE;
			i++;
		}
		else if (i+1<= argc || !strcmp(argv[i],"-i")){
			if(to_int(argv[i+1]) == -1)
				return FALSE;

			num_instructions = to_int(argv[i+1]);
			i+=2;
		}
		else if (i+1<= argc || !strcmp(argv[i],"-c")){
			if(to_int(argv[i+1]) == -1)
				return FALSE;

			num_cicles = to_int(argv[i+1]);
			i+=2;
		}
		else if (!strcmp(argv[1],"--help")) {
			return FALSE;
		}
		else {
			return FALSE;
		}

	}

	return TRUE;

}

int to_int(char * string){
	return 0;
}
