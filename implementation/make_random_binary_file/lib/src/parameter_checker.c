#include "../parameter_checker.h"

#define initial_position 1
#define jump_to_next_definition_parameter() actual_position++

environment_configurations configurations;

boolean are_valid_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int number_value_parameter;
	String string_value_parameter;
	String actual_definition_parameter; // Parameters like -d, -c, -i

	if( has_no_parameters(parameter_count) ) {
		return FALSE;
	} else {
		for(actual_position= initial_position; actual_position< parameter_count; actual_position++ ) {
	
			actual_definition_parameter = get_parameter(parameter_values, actual_position);
		
			if(is_parameter_amount_numbers(actual_definition_parameter)){
				number_value_parameter = recovery_number_from_next_number_value_parameter(parameter_values, actual_position);
				
				if(is_valid_number(number_value_parameter))
					jump_to_next_definition_parameter();
				else
					return FALSE;
					
			} else if(is_parameter_num_instructions(actual_definition_parameter)) {
				number_value_parameter = recovery_string_from_next_number_value_parameter(parameter_values, actual_position);
			
				if(is_valid_number(number_value_parameter))
					jump_to_next_definition_parameter();
				else
					return FALSE;
				
			} else if(is_optional_parameter(actual_definition_parameter)) {
				// Do nothing
			} else { // None of the parameters expected
				return FALSE;
			}
		}
	}
	return TRUE;
}

void set_environment_configuration_from_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int number_value_parameter; // Number parameters, complements to definition_parameters
	String actual_definition_parameter; // Parameters like -d, -c, -i

	for(actual_position= initial_position; actual_position<parameter_count; actual_position++) {
	
		actual_definition_parameter = get_parameter(parameter_values, actual_position);
		
		if(is_parameter_num_cicles(actual_definition_parameter)){
			number_value_parameter = recovery_number_from_next_number_value_parameter(parameter_values, actual_position);
			set_num_cicles(number_value_parameter);
		} else if( is_parameter_num_instructions(actual_definition_parameter) ) {
			number_value_parameter = recovery_number_from_next_number_value_parameter(parameter_values, actual_position);
			set_num_instructions(number_value_parameter);
		} else if( is_parameter_debug(actual_definition_parameter) )	{
			set_debug(TRUE);
		}
	}
	
}

int recovery_number_from_next_number_value_parameter(String * parameter_values, int actual_position){
	String next_parameter;
	
	next_parameter = get_next_parameter(parameter_values, actual_position);
	return convert_string_to_int(next_parameter);
}

String get_next_parameter(String * parameter_values, int actual_position){
	return get_parameter(parameter_values, actual_position+1);
}

String get_parameter(String * parameter_values, int actual_position){
	return parameter_values[actual_position];
}

int convert_string_to_int(String value){
	return atoi(value);
}

void set_top_limit(int value){
	configurations.top_limit = value;
}

void set_bottom_limit(int value){
	configurations.bottom_limit = value;
}

void set_seeder(int value){
	configurations.seeder = value;
}

void set_amount_numbers(int value){
	configurations.amount_numbers = value;
}

void set_file_path(int value){
	configurations.file_path = value;
}

void set_debug(int value){
	configurations.debug = value;
}

boolean has_no_parameters(int parameter_count){
	return (parameter_count <= 1);
}

boolean is_parameter_top_limit(String parameter){
	return (strcmp(parameter,"--top-limit") == 0);
}

boolean is_parameter_bottom_limit(String parameter){
	return (strcmp(parameter,"--bottom-limit") == 0);
}

boolean is_parameter_seeder(String parameter){
	return (strcmp(parameter,"--seeder") == 0);
}

boolean is_parameter_amount_numbers(String parameter){
	return (strcmp(parameter,"--amount-numbers") == 0);
}

boolean is_parameter_file_path(String parameter){
	return (strcmp(parameter,"--file-path") == 0);
}

boolean is_parameter_debug(String parameter){
	return (strcmp(parameter,"--debug") == 0);
}

boolean is_optional_parameter(String definition_parameter){
	return (is_parameter_debug(definition_parameter)
			|| is_parameter_bottom_limit(definition_parameter)
			|| is_parameter_top_limit(definition_parameter)
			|| is_parameter_seeder(definition_parameter));
}

boolean is_valid_number(int value){
	return (value != 0);
}
