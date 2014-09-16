#ifndef STRUCT_C
#define STRUCT_C // Begin of Definition

#include <time.h>

#define String char *

typedef enum enm_boolean {
FALSE, TRUE
} boolean;

typedef struct tp_environment_configurations{
	String file_path;
	String output_file_path;
	String aux_output_file_path;
	int amount_numbers;
	boolean debug;
}environment_configurations;

typedef struct tp_interval{
	clock_t start_time;
	clock_t end_time;
} interval;

typedef struct tp_debug_informations{
	interval process;
	interval recovery_array;
	interval transform_array_to_bin_tree;
	interval transform_bin_tree_to_array;
	interval write_array_on_binary_file;
	interval write_array_on_text_file;
} debug_informations;

typedef struct tp_bin_tree_node {
        int value;
        struct tp_bin_tree_node * up;
        struct tp_bin_tree_node * left;
        struct tp_bin_tree_node * right;
} bin_tree_node;

#endif // End of Definition
