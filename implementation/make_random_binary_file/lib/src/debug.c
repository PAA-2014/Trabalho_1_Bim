#include "../debug.h"

environment_configurations configurations;
debug_informations debug;

void init_process_debug(){

	if(configurations.debug){
		debug.process.start_time = get_actual_time();
		printf("\nGenerating and writing %d numbers.\n",configurations.amount_numbers);
	}
}

void init_generate_array_debug(){

	if(configurations.debug){
		debug.generate_array.start_time = get_actual_time();
		printf("\nStarting the generate of %d numbers.\n",configurations.amount_numbers);
	}
}

void init_write_on_binary_file(){

	if(configurations.debug){
		debug.write_on_binary_file.start_time = get_actual_time();
		printf("\nStarting the write of %d numbers on binary file \"%s\".\n",configurations.amount_numbers, configurations.file_path);
	}
}

void init_write_on_text_file(){

	if(configurations.debug){
		debug.write_on_text_file.start_time = get_actual_time();
		printf("\nStarting the write of %d numbers on text file \"%s\".\n",configurations.amount_numbers, configurations.aux_file_path);
	}
}

void end_process_debug(){

	if(configurations.debug){
		debug.process.end_time = get_actual_time();
		printf("Generated and wrote %d numbers in %f seconds.\n\n", configurations.amount_numbers, calc_time(debug.process));
	}
}

void end_generate_array_debug(){

	if(configurations.debug){
		debug.generate_array.end_time = get_actual_time();
		printf("Generated %d numbers in %f seconds.\n\n",configurations.amount_numbers, calc_time(debug.generate_array));
	}
}

void end_write_on_binary_file(){

	if(configurations.debug){
		debug.write_on_binary_file.end_time = get_actual_time();
		printf("Wrote %d numbers on binary file \"%s\" in %f seconds.\n\n",configurations.amount_numbers, configurations.file_path, calc_time(debug.write_on_binary_file));
	}
}

void end_write_on_text_file(){

	if(configurations.debug){
		debug.write_on_text_file.end_time = get_actual_time();
		printf("Wrote %d numbers on text file \"%s\" in %f seconds.\n\n",configurations.amount_numbers, configurations.aux_file_path, calc_time(debug.write_on_text_file));
	}
}
