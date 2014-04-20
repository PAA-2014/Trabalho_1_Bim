#ifndef STRUCT_C
#define STRUCT_C

#define String char *

typedef enum enm_boolean{
FALSE, TRUE
}boolean;

typedef struct tp_environment_configurations{
	int seeder;
	int amount_numbers;
	int top_limit;
	int bottom_limit;
	boolean debug;
	String file_path;
}environment_configurations;

#endif
