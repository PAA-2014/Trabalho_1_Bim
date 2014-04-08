#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main(int argc, char ** argv){

	// Vars
	int i,aux_num_instructions;
	double total_time = 0, avarage_time;
	cicle * cicles = (cicle *) malloc(sizeof(cicle)*num_cicles);

	// Logic
	for(i=0;i<num_cicles;i++){
		cicles[i] = (cicle *) malloc(sizeof(cicle)*1);

		aux_num_instructions = num_instructions;

		cicles[i]->start = clock();
		while(aux_num_instructions--);
		cicles[i]->end = clock();

		cicles[i]->spend_time= (cicles[i]->end - cicles[i]->start / (double)CLOCKS_PER_SEC);
		total_time += cicles[i]->spend_time;
	}

/*
	avarage = total_time/max_executions;
	printf("\n\n Tempo Médio : %f\n",avarage);

	printf("Instruções por Segundo : %f\n\n",max_n/avarage);
*/
	return 0;
}

boolean check_parameters(int argc, char ** argv){
	return FALSE;
}
