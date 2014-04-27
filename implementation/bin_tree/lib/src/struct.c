#ifndef STRUCT_C
#define STRUCT_C // Begin of Definition

#define String char *

typedef struct tp_bin_tree_node {
        int value;
        struct tp_bin_tree_node * up;
        struct tp_bin_tree_node * left;
        struct tp_bin_tree_node * right;
} bin_tree_node;

typedef enum enm_boolean {
FALSE, TRUE
} boolean;

typedef struct tp_environment_configurations{
	String file_path;
	boolean debug;
}environment_configurations;

#endif // End of Definition
