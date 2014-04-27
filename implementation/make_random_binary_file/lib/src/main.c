#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#include <sys/ioctl.h>
#include <unistd.h>*/

#include "struct.c"
#include "../make_random_binary_file.h"
#include "../parameter_checker.h"

#define ERROR -1
#define SUCCESS_END_OF_PROGRAM 0

environment_configurations configurations;

int main(int parameter_count, String * parameter_values){

	if(are_valid_parameters(parameter_count, parameter_values)){
		set_environment_configuration_from_parameters(parameter_count, parameter_values);
		make_random_binary_file();
	} else {
		printf("ERROR : INVALID PARAMETERS\n\n");
		return ERROR;
	}
	
	/* Como recuperar o tamanho do terminal
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    */

	return SUCCESS_END_OF_PROGRAM;
}
