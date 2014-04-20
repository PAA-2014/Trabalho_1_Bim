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

/** TODO
	argument Seeder
	argument Quantitative Random Numbers
	argument Top Limit
	argument Bottom Limit
	argument File Path to Write
	argument Debug
*/

environment_configurations configurations;

int main(int parameter_count, String * parameter_values){

	if(are_valid_parameters(parameter_count, parameter_values)){
		set_environment_configuration_from_parameters(parameter_count, parameter_values);
		execute_stress_test();
	} else {
		printf("ERROR : INVALID PARAMETERS\n\n");
		return ERROR;
	}

	configurations.amount_numbers = 1000;
	configurations.seeder = 1;
	configurations.top_limit = 10;
	configurations.bottom_limit = 1;
	configurations.file_path = "/home/arthur/teste.rand";
	
	make_random_binary_file();
	
	/* Como recuperar o tamanho do terminal
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    */

	return SUCCESS_END_OF_PROGRAM;
}
