#include "../debug.h"

environment_configurations configurations;
debug_informations debug;

void log_init_process_debug(){
	if(configurations.debug){
		debug.process.start_time = get_actual_time();
		printf("\nStart of Tree Sort.\n",configurations.amount_numbers);
	}
}

void log_init_recovery_array(){
	if(configurations.debug){
		debug.recovery_array.start_time = get_actual_time();
		printf("\nRecovering %d numbers from file \"%s\".\n",configurations.amount_numbers, configurations.file_path);
	}
}

void log_init_transform_array_on_binary_tree(){
	if(configurations.debug){
		debug.transform_array_to_bin_tree.start_time = get_actual_time();
		printf("\nInputing %d numbers from array in binary tree.\n",configurations.amount_numbers);
	}
}

void log_init_transform_binary_tree_on_array(){
	if(configurations.debug){
		debug.transform_bin_tree_to_array.start_time = get_actual_time();
		printf("\nOutputing %d numbers from binary tree to array.\n",configurations.amount_numbers);
	}
}

void log_init_write_array_on_binary_file(){
	if(configurations.debug){
		debug.write_array_on_binary_file.start_time = get_actual_time();
		printf("\nWriting %d numbers in binary file \"%s\".\n",configurations.amount_numbers, configurations.output_file_path);
	}
}

void log_init_write_array_on_text_file(){
	if(configurations.debug){
		debug.write_array_on_text_file.start_time = get_actual_time();
		printf("\nWriting %d numbers in text file \"%s\".\n",configurations.amount_numbers, configurations.aux_output_file_path);
	}
}

void log_end_process_debug(){

	if(configurations.debug){
		debug.process.end_time = get_actual_time();
		printf("\nSorted %d numbers in %f seconds.\nThe End\n\n", configurations.amount_numbers, calc_time(debug.process));
	}
}

void log_end_recovery_array(){
	if(configurations.debug){
		debug.recovery_array.end_time = get_actual_time();
		printf("Recovered %d numbers from file \"%s\" in %f seconds.\n",configurations.amount_numbers, configurations.file_path, calc_time(debug.recovery_array));
	}
}

void log_end_transform_array_on_binary_tree(){
	if(configurations.debug){
		debug.transform_array_to_bin_tree.end_time = get_actual_time();
		printf("Inputed %d numbers in binary tree in %f seconds.\n",configurations.amount_numbers, calc_time(debug.transform_array_to_bin_tree));
	}
}

void log_end_transform_binary_tree_on_array(){
	if(configurations.debug){
		debug.transform_bin_tree_to_array.end_time = get_actual_time();
		printf("Outputed %d numbers from binary tree to array in %f seconds.\n",configurations.amount_numbers, calc_time(debug.transform_bin_tree_to_array));
	}
}

void log_end_write_array_on_binary_file(){
	if(configurations.debug){
		debug.write_array_on_binary_file.end_time = get_actual_time();
		printf("Wrote %d numbers in binary file \"%s\" in %f seconds.\n",configurations.amount_numbers, configurations.output_file_path, calc_time(debug.write_array_on_binary_file));
	}
}

void log_end_write_array_on_text_file(){
	if(configurations.debug){
		debug.write_array_on_text_file.end_time = get_actual_time();
		printf("Wrote %d numbers in text file \"%s\" in %f seconds.\n",configurations.amount_numbers, configurations.aux_output_file_path, calc_time(debug.write_array_on_text_file));
	}
}
