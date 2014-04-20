#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.c"
#include "../make_random_binary_file.h"
#include "../parameter_checker.h"

/** TODO 
	argument Seeder
	argument Quantitative Random Numbers
	argument Max Number	
	argument Min Number	
	argument File Path to Write
	search for LC_NUMERIC, and print formatation
*/

environment_configurations configurations;

int main(int parameter_count, String * parameter_values){

	configurations.amount_numbers = 1000;
	configurations.seeder = 1;
	configurations.top_limit = 10;
	configurations.bottom_limit = 1;
	configurations.file_path = "/home/arthur/teste.rand";
	
	make_random_binary_file();

	return 0;
}
