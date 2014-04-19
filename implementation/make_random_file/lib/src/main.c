#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.c"

LC_NUMERIC
#
decimal_point    "<period>"
thousands_sep    "<comma>"
grouping         <3>
#
END LC_NUMERIC

/** TODO 
	argument Seeder
	argument Quantitative Random Numbers
	argument Max Number	
	argument Min Number	
	argument File Path to Write
*/
int main(int parameter_count, String * parameter_values){

	int teste = 10000000;
	
	LC_NUMERIC->decimal_point = ",";
	LC_NUMERIC->thousands_sep = ".";
	LC_NUMERIC->grouping = 3;

	printf("%d\n",teste);

	return 0;
}
