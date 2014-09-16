#include "../bin_tree.h"

environment_configurations configurations;

int * sorted_array;
int actual_position;

void tree_sort(){
	log_init_process_debug();
	
	int * unsorted_array;
	bin_tree_node * root_node;

	configurations.amount_numbers = get_amount_numbers_of_file(configurations.file_path, sizeof(int));
	
	log_init_recovery_array();
	unsorted_array = recovery_array_from_file(configurations.file_path, configurations.amount_numbers);
	log_end_recovery_array();
	
	log_init_transform_array_on_binary_tree();
	root_node = transform_array_to_bin_tree(unsorted_array, configurations.amount_numbers);
	log_end_transform_array_on_binary_tree();
	
	log_init_transform_binary_tree_on_array();
	init_sorted_array();
	transform_bin_tree_to_array(root_node);
	//free_bin_tree(root_node);
	log_end_transform_binary_tree_on_array();
	
	log_init_write_array_on_binary_file();
	write_array_on_binary_file(configurations.output_file_path, sorted_array, configurations.amount_numbers);
	log_end_write_array_on_binary_file();
	
	//write_log_on_text_file(configurations.log_file_path);
	
	log_init_write_array_on_text_file();
	write_array_on_text_file(configurations.aux_output_file_path, sorted_array, configurations.amount_numbers);
	log_end_write_array_on_text_file();
	
	free(unsorted_array);
	free(sorted_array);
	
	log_end_process_debug();
}

bin_tree_node * transform_array_to_bin_tree(int * array, int array_size){

	int actual_position;
	bin_tree_node * root_node;
	
	root_node = NULL;
	
	for(actual_position =0; actual_position< array_size; actual_position++)
		root_node = add_bin_tree_node(root_node, array[actual_position]);
	
	return root_node;
}

bin_tree_node * add_bin_tree_node(bin_tree_node * root, int value){

	if(root == NULL)
        return new_bin_tree_node(value);
        
    if(root->value == value){
    	root->count++;
    	return root;
    }

	if(value >= root->value){
		root->right = add_bin_tree_node(root->right,value);
		root->right->up = root;
	}
	else{
		root->left = add_bin_tree_node(root->left,value);
		root->left->up = root;
	}

	return root;

}

bin_tree_node * new_bin_tree_node(int value){

	bin_tree_node * node = (bin_tree_node *)malloc(sizeof(bin_tree_node)*1);

	node->up =node->right =node->left =NULL;
	node->count =1;
	node->value =value;

	return node;
}

void free_bin_tree(bin_tree_node * root){

	if(root == NULL)
		return;

	free_bin_tree(root->left);
	free_bin_tree(root->right);
	free(root);
}

void transform_bin_tree_to_array(bin_tree_node * root){

	if(root == NULL)
		return;

	int actual_position;

	transform_bin_tree_to_array(root->left);
	for(actual_position =0;actual_position <root->count; actual_position++)
		add_node_to_array(root->value);
	transform_bin_tree_to_array(root->right);
}

void add_node_to_array(int value){

	sorted_array[actual_position] = value;
	actual_position++;
}

void init_sorted_array(){

	actual_position = 0;
	sorted_array = new_int_array(configurations.amount_numbers);
}
