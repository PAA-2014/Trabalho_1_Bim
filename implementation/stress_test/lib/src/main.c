#include "struct.c"
#include "../stress_test.h"
#include "../parameter_checker.h"

#define ERROR -1
#define SUCCESS_END_OF_PROGRAM 0

environment_configurations configurations;

int main(int parameter_count, String * parameter_values){

	if(are_valid_parameters(parameter_count, parameter_values)){
		set_environment_configuration_from_parameters(parameter_count, parameter_values);
		execute_stress_test();
	} else {
		printf("ERROR : INVALID PARAMETERS\n\n");
		return ERROR;
	}
	
	return SUCCESS_END_OF_PROGRAM;
}
