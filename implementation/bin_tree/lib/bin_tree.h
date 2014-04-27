#ifndef BIN_TREE_H
#define BIN_TREE_H // Begin of Definition

#include "file.h"
#include "src/struct.c"

#include <stdio.h>
#include <stdlib.h>

bin_tree_node * mount_bin_tree();

bin_tree_node * transform_array_to_bin_tree(int * array, int array_size);

bin_tree_node * add_bin_tree_node(bin_tree_node * root, bin_tree_node * new_node);

bin_tree_node * new_bin_tree_node(int value);

void print_bin_tree(bin_tree_node * root);

#endif // End of Definition
