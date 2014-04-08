#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"

int main(int argc, char ** argv){

	bin_tree_node * root = (bin_tree_node *)malloc(sizeof(bin_tree_node)*1);

	root = new_bin_tree_node(10);
	root = add_bin_tree_node(root,new_bin_tree_node(20));
	root = add_bin_tree_node(root,new_bin_tree_node(4));
	root = add_bin_tree_node(root,new_bin_tree_node(1));
	root = add_bin_tree_node(root,new_bin_tree_node(200));
	root = add_bin_tree_node(root,new_bin_tree_node(7));
	root = add_bin_tree_node(root,new_bin_tree_node(10));
	root = add_bin_tree_node(root,new_bin_tree_node(4));
	root = add_bin_tree_node(root,new_bin_tree_node(3));
	root = add_bin_tree_node(root,new_bin_tree_node(77));
	print_bin_tree(root);
	printf("\n");

	return 0;

}
