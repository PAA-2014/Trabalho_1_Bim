#include <stdio.h>
#include <stdlib.h>

#include "struct.c"
#include "../make_random_binary_file.h"
#include "../parameter_checker.h"
#include "../util.h"

#define SUCCESS_END_OF_PROGRAM 0

environment_configurations configurations;

inline void print_general_error();

int main(int parameter_count, String * parameter_values){

	if(are_valid_parameters(parameter_count, parameter_values)){
		set_environment_configuration_from_parameters(parameter_count, parameter_values);
		
		if(validate_environment_configurations())
			make_random_binary_file();
		else{
			print_general_error();
			return ERROR;
		}
	} else{
		print_general_error();
		return ERROR;
	}

	return SUCCESS_END_OF_PROGRAM;
}

inline void print_general_error(){
	printf("ERROR : INVALID PARAMETERS\n\n");
}
