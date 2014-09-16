#include "../util.h"

#define FORMAT_BASE "%0?d "
#define CHAR_TO_REMOVE '?'

#define OUTPUT_LINE_LIMIT 140

String replace_last_char(String string_base, char to_remove, String to_put){

	if(!is_valid_string(string_base) || !is_valid_string(to_put))
		return NULL;

	String final_string;
	String before;
	String after;

	int new_total_size;
	int position_to_remove;
	
	position_to_remove = get_last_pos_character(string_base, to_remove);
	
	before = get_before(string_base, position_to_remove);
	after = get_after(string_base, position_to_remove);

	new_total_size = string_lenght(before) + string_lenght(to_put) + string_lenght(after);

	final_string = new_string(new_total_size);

	strcat(final_string, before);
	strcat(final_string, to_put);
	strcat(final_string, after);
	
	free(before);
	free(after);
	
	return final_string;
}

int get_last_pos_character(String string_base, char char_searched){
	if(!is_valid_string(string_base))
		return ERROR;

	return strrchr(string_base, char_searched)-string_base;
}

String get_before(String string_base, int position_to_cut){

	char * before;
	int size_before;
	
	size_before = position_to_cut;
	
	before = new_string(size_before);
	strncpy(before, string_base, size_before);
	before[size_before] = '\0';

	return before;
}

String get_after(String string_base, int position_to_cut){

	char * after;
	int size_after;
	
	size_after = string_lenght(string_base) - (position_to_cut);

	after = new_string(size_after);
	strncpy(after, &string_base[position_to_cut+1], size_after);
	after[size_after] = '\0';
	
	return after;
}

String new_string(int size){

	String new_string;
	
	new_string = (char *)malloc((size+1)*sizeof(char));
	new_string[size] = '\0';
	
	return new_string;
}

int string_lenght(String value){

	return strlen(value);
}

boolean are_equal_strings(String string1, String string2){
	return (strcmp(string1, string2) == 0);
}

boolean is_valid_string(String value){
	return (value != NULL && !are_equal_strings("",value));
}

int convert_string_to_int(String value){
	return atoi(value);
}

boolean is_valid(int value){
	return (value != 0);
}

boolean is_valid_natural_number(int value){
	return (is_valid(value) && (value > 0));
}

int count_algarisms_from_number(unsigned int value){
	if(value == 0)
		return 0;
	
	value /= 10;
	
	return count_algarisms_from_number(value)+1;
}

String convert_int_to_string(int number){
	
	int actual_position;
	int algarisms_count;
	
	String string_value;
	
	algarisms_count = count_algarisms_from_number(number);
	string_value = new_string(algarisms_count);
	
	for(actual_position= algarisms_count-1; actual_position >= 0; actual_position--){	
		if(number == 0)
			break;
		else{
			string_value[actual_position] = (number%10) + '0';
			number /= 10;
		}
	}
	return string_value;	
}

int get_major_number_from_unsorted_array(int * array, int array_size){
	int major_number;
	int actual_position;
	
	for(actual_position= 0; actual_position< array_size; actual_position++)
		if(actual_position == 0)
			major_number = array[actual_position];
		else
			if(major_number < array[actual_position])
				major_number = array[actual_position];
				
	return major_number;
}

int count_max_algarisms(int * random_array, int amount_numbers){
	int major_number;
	int algarisms_count;

	major_number = get_major_number_from_unsorted_array(random_array, amount_numbers);
	algarisms_count = count_algarisms_from_number(major_number);
	
	return algarisms_count;
}

String generate_format_to_impress(int max_algarisms){
	
	String format;
	String to_replace;
	
	to_replace = convert_int_to_string(max_algarisms);
	format = replace_last_char(FORMAT_BASE, CHAR_TO_REMOVE, to_replace);
	
	return format;
}

int * new_int_array(unsigned int size){
	return (int *)malloc(sizeof(int)*size);
}

boolean is_end_of_line(int actual_number, int algarisms_per_number){
	return ((actual_number % numbers_to_write_per_line(algarisms_per_number)) == 0); 
}

int numbers_to_write_per_line(int algarisms_per_number){
	return (OUTPUT_LINE_LIMIT/(algarisms_per_number+1));// +1 because space count as character
}

clock_t get_actual_time(){
	return clock();
}

double calc_time(interval interval_time){
	return ((interval_time.end_time - interval_time.start_time) / (double)CLOCKS_PER_SEC);
}
