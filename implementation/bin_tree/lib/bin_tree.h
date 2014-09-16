#ifndef BIN_TREE_H
#define BIN_TREE_H // Begin of Definition

#include "file.h"
#include "src/struct.c"

#include <stdio.h>
#include <stdlib.h>

void tree_sort();

bin_tree_node * transform_array_to_bin_tree(int * array, int array_size);

bin_tree_node * add_bin_tree_node(bin_tree_node * root, bin_tree_node * new_node);

bin_tree_node * new_bin_tree_node(int value);

void free_bin_tree(bin_tree_node * root);

void transform_bin_tree_to_array(bin_tree_node * root);

void add_node_to_array(int value);

void log_init_sorted_array();

#endif // End of Definition
