#include <stdio.h>
#include <stdlib.h>
#include "../bin_tree.h"

int main(int argc, char ** argv){

	bin_tree_node * root = (bin_tree_node *)malloc(sizeof(bin_tree_node)*1);
	root = NULL;
	
	int value_scanned;
	
	printf("\nDigite 0 para imprimir a árvore.\n\n");
	
	do{
		printf("\nDigite um valor : ");
		scanf("%d",&value_scanned);
		
		if(!value_scanned)
			break;
			
		root = add_bin_tree_node(root,new_bin_tree_node(value_scanned));
	}while(1);
	
	print_bin_tree(root);
	
	printf("\n");

	return 0;

}
