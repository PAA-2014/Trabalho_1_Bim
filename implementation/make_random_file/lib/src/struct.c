#ifndef STRUCT_C
#define STRUCT_C

#define String char *

typedef struct tp_environment_configurations{
	int seeder;
	int qtd_numbers;
	int max_number;
	int min_number;
	String file_path;
}environment_configurations;

#endif
