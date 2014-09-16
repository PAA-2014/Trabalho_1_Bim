#include "../make_random_binary_file.h"

environment_configurations configurations;
debug_informations debug;

void make_random_binary_file(){

	log_init_process_debug();

	int * random_array;
	
	set_random_seeder(configurations.seeder);

	log_init_generate_array_debug();
	random_array = make_random_array(configurations.amount_numbers, configurations.bottom_limit, configurations.top_limit);
	log_end_generate_array_debug();
	
	log_init_write_on_binary_file();
	write_array_on_binary_file(configurations.file_path, random_array, configurations.amount_numbers);
	log_end_write_on_binary_file();
	
	log_init_write_on_text_file();
	write_array_on_text_file(configurations.aux_file_path, random_array, configurations.amount_numbers);
	log_end_write_on_text_file();
	
	log_end_process_debug();
}

inline void set_random_seeder(int seeder){

	srand(seeder);
}

int * make_random_array(int amount_numbers, int bottom_limit, int top_limit){

	int actual_position;
	int * random_array;
	
	random_array = new_int_array(amount_numbers);
	
	for(actual_position = 0; actual_position < amount_numbers; actual_position++)
		random_array[actual_position] = get_next_random_number(bottom_limit, top_limit);
		
	return random_array;
}

int get_next_random_number(int bottom_limit, int top_limit){

	unsigned int random_number;
	
	random_number = rand();
	
	if(is_valid(top_limit) || is_valid(bottom_limit))
		return limit_random_number(random_number, bottom_limit, top_limit);
	else
		return random_number;
}

int limit_random_number(unsigned int random_number, int bottom_limit, int top_limit){

	int limited_random_number;
	
	limited_random_number = random_number;
	
	if(is_valid(top_limit) && is_valid(bottom_limit))
		limited_random_number = limit_random_bottom_and_top(limited_random_number, bottom_limit, top_limit);
	else
		if(is_valid(top_limit))
			limited_random_number = limit_random_top(limited_random_number, top_limit);
			
		else if(is_valid(bottom_limit))
			limited_random_number = limit_random_bottom(limited_random_number, bottom_limit);
			
	return limited_random_number;
}

int limit_random_bottom_and_top(int random_number, int bottom_limit, int top_limit){

	random_number = limit_random_top(random_number, top_limit - bottom_limit);
	random_number = limit_random_bottom(random_number, bottom_limit);
	
	return random_number;
}

int limit_random_top(int random_number, int top_limit){
	return (random_number % top_limit+1);
}

int limit_random_bottom(int random_number, int bottom_limit){
	return (random_number + bottom_limit);
}
