#include "../parameter_checker.h"

#define initial_position 1
#define jump_to_next_definition_parameter() actual_position++

environment_configurations configurations;

boolean are_valid_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int quantitative_parameter; // Number parameters, complements to definition_parameters
	String actual_definition_parameter; // Parameters like -d, -c, -i

	if( has_no_parameters(parameter_count) ) {
		return FALSE;
	} else {
		for(actual_position= initial_position; actual_position< parameter_count; actual_position++ ) {
	
			actual_definition_parameter = get_parameter(parameter_values, actual_position);
		
			if(is_parameter_num_cicles(actual_definition_parameter)){
				quantitative_parameter = recovery_number_from_next_quantitative_parameter(parameter_values, actual_position);
				
				if(is_valid_number(quantitative_parameter))
					jump_to_next_definition_parameter();
				else
					return FALSE;
					
			} else if( is_parameter_num_instructions(actual_definition_parameter) ) {
				quantitative_parameter = recovery_number_from_next_quantitative_parameter(parameter_values, actual_position);
			
				if(is_valid_number(quantitative_parameter))
					jump_to_next_definition_parameter();
				else
					return FALSE;
				
			} else if( is_parameter_debug(actual_definition_parameter) ) {
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
	int quantitative_parameter; // Number parameters, complements to definition_parameters
	String actual_definition_parameter; // Parameters like -d, -c, -i

	for(actual_position= initial_position; actual_position<parameter_count; actual_position++) {
	
		actual_definition_parameter = get_parameter(parameter_values, actual_position);
		
		if(is_parameter_num_cicles(actual_definition_parameter)){
			quantitative_parameter = recovery_number_from_next_quantitative_parameter(parameter_values, actual_position);
			set_num_cicles(quantitative_parameter);
		} else if( is_parameter_num_instructions(actual_definition_parameter) ) {
			quantitative_parameter = recovery_number_from_next_quantitative_parameter(parameter_values, actual_position);
			set_num_instructions(quantitative_parameter);
		} else if( is_parameter_debug(actual_definition_parameter) )	{
			set_debug(TRUE);
		}
	}
	
}

int recovery_number_from_next_quantitative_parameter(String * parameter_values, int actual_position){
	String next_parameter;
	
	next_parameter = get_next_parameter(parameter_values, actual_position);
	return convert_string_to_int(next_parameter);
}

void set_num_instructions(int value){
	configurations.num_instructions = value;
}

void set_num_cicles(int value){
	configurations.num_cicles = value;
}

void set_debug(boolean value){
	configurations.debug = TRUE;
}

boolean has_no_parameters(int parameter_count){
	return (parameter_count <= 1);
}

boolean is_parameter_num_cicles(String parameter){
	return (strcmp(parameter,"-c") == 0);
}

boolean is_parameter_num_instructions(String parameter){
	return (strcmp(parameter,"-i") == 0);
}

boolean is_parameter_debug(String parameter){
	return (strcmp(parameter,"-d") == 0);
}

int convert_string_to_int(String value){
	return atoi(value);
}

boolean is_valid_number(int value){
	return (value != 0);
}

String get_parameter(String * parameter_values, int actual_position){
	return parameter_values[actual_position];
}

String get_next_parameter(String * parameter_values, int actual_position){
	return get_parameter(parameter_values, actual_position+1);
}
