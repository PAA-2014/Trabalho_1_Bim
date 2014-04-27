#include "../bin_tree.h"

environment_configurations configurations;

bin_tree_node * mount_bin_tree(){
	bin_tree_node * root_node;
	int * array;
	int array_size;
	
	array_size = get_amount_numbers_of_file(configurations.file_path, sizeof(int));
	array = recovery_array_from_file(configurations.file_path, array_size);
	root_node = transform_array_to_bin_tree(array, array_size);
	
	free(array);
	
	return root_node;
}

bin_tree_node * transform_array_to_bin_tree(int * array, int array_size){

	int actual_position;
	bin_tree_node * root_node;
	bin_tree_node * temp_node;
	
	root_node = NULL;
	
	for(actual_position =0; actual_position< array_size; actual_position++){
		temp_node = new_bin_tree_node(array[actual_position]);
		root_node = add_bin_tree_node(root_node, temp_node);
	}
	
	free(temp_node);
	
	return root_node;
}

bin_tree_node * add_bin_tree_node(bin_tree_node * root, bin_tree_node * new_node){

	if(root == NULL)
        return new_node;

	if(new_node->value >= root->value){
		root->right = add_bin_tree_node(root->right,new_node);
		root->right->up = root;
	}
	else{
		root->left = add_bin_tree_node(root->left,new_node);
		root->left->up = root;
	}

	return root;

}

bin_tree_node * new_bin_tree_node(int value){
	bin_tree_node * node = (bin_tree_node *)malloc(sizeof(bin_tree_node)*1);

	node->up =node->right =node->left =NULL;
	node->value =value;

	return node;
}

void print_bin_tree(bin_tree_node * root){

	if(root == NULL)
		return;

	print_bin_tree(root->left);
	printf("%d ",root->value);
	print_bin_tree(root->right);
}
