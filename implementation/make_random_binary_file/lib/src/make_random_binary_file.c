#include "../make_random_binary_file.h"

environment_configurations configurations; // LOOK AT THIS, THIS PART OF CODE IS AMAZING

void make_random_binary_file(){
	
	int * random_array;
	int aux_amount_numbers;
	
	set_random_seeder(configurations.seeder);
	
	random_array = make_random_array(configurations.amount_numbers, configurations.bottom_limit, configurations.top_limit);
	
	write_random_array_on_binary_file(configurations.file_path, random_array, configurations.amount_numbers);
	
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

int * new_int_array(unsigned int size){
	return (int *)malloc(sizeof(int)*size);
}

int get_next_random_number(int bottom_limit, int top_limit){
	unsigned int random_number;
	
	random_number = rand();
	
	if(is_valid(top_limit) || is_valid(bottom_limit))
		return limit_random_number(random_number, bottom_limit, top_limit);
	else
		return random_number;
}

boolean is_valid(int limit){
	return (limit != 0);
}

int limit_random_number(unsigned int random_number, int bottom_limit, int top_limit){
	int limited_random_number;
	
	limited_random_number = random_number;

	if(is_valid(top_limit))
		limited_random_number = limit_random_top(limited_random_number, top_limit);
		
	if(is_valid(bottom_limit))
		limited_random_number = limit_random_bottom(limited_random_number, bottom_limit);
	
	return limited_random_number;
}

int limit_random_top(int random_number, int top_limit){
	return (random_number % top_limit+1);
}

int limit_random_bottom(int random_number, int bottom_limit){
	return (random_number + bottom_limit);
}
