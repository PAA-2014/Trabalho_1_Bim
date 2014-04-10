#ifndef STRUCT_C
#define STRUCT_C // Begin of Definition

typedef struct tp_bin_tree_node {

        int value;
        struct tp_bin_tree_node * up;
        struct tp_bin_tree_node * left;
        struct tp_bin_tree_node * right;

} bin_tree_node;

#endif // End of Definition
