#ifndef BIN_TREE_H
#define BIN_TREE_H // Begin of Definition

#include <stdio.h>
#include <stdlib.h>
#include "src/struct.c"

bin_tree_node * add_bin_tree_node(bin_tree_node * root, bin_tree_node * new_node);

bin_tree_node * new_bin_tree_node(int value);

void print_bin_tree(bin_tree_node * root);

#endif // End of Definition
