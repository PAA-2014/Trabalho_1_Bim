#ifndef STRUCT_C
#define STRUCT_C

#define String char *

#include <time.h>

typedef enum enm_boolean{
FALSE, TRUE
}boolean;

typedef struct tp_interval{
	clock_t start_time;
	clock_t end_time;
} interval;

typedef struct tp_debug_informations{
	interval process;
	interval generate_array;
	interval write_on_binary_file;
	interval write_on_text_file;
} debug_informations;

typedef struct tp_environment_configurations{
	int seeder;
	int amount_numbers;
	int top_limit;
	int bottom_limit;
	boolean debug;
	String file_path;
	String aux_file_path;
}environment_configurations;

#endif
