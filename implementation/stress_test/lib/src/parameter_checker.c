#include "../parameter_checker.h"

#define initial_position 1
#define jump_to_next_definition_parameter() actual_position++

// Init of Definition Parameters
#define short_debug "-d"
#define extensive_debug "-debug"

#define short_cicles "-c"
#define extensive_cicles "-cicles"

#define short_instructions "-i"
#define extensive_instructions "-instructions"
// End of Definition Parameters

environment_configurations configurations;

boolean are_valid_parameters(int parameter_count, String * parameter_values){
	if(has_no_parameters(parameter_count)) {
		return FALSE;
	} else {
		return validate_parameters(parameter_count, parameter_values);
	}
}

boolean has_no_parameters(int parameter_count){
	return (parameter_count <= 1);
}

boolean validate_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	String actual_definition_parameter; // Parameters like -d, -c, -i
	
	for(actual_position= initial_position; actual_position< parameter_count; actual_position++ ){
		actual_definition_parameter = get_parameter(parameter_values, actual_position);

		if(is_optional_parameter(actual_definition_parameter))
			continue;
		else if(is_mandatory_parameter(actual_definition_parameter)){
			if(is_valid_next_value_parameter(actual_position, parameter_values))
				jump_to_next_definition_parameter();
			else
				return FALSE;
		}
		else
			return FALSE;
	}
	return TRUE;
}

String get_parameter(String * parameter_values, int actual_position){
	return parameter_values[actual_position];
}

boolean is_optional_parameter(String definition_parameter){
	return (is_parameter_debug(definition_parameter));
}

boolean is_mandatory_parameter(String definition_parameter){
	return (is_parameter_num_cicles(definition_parameter)
			|| is_parameter_num_instructions(definition_parameter));
}

boolean is_valid_next_value_parameter(int actual_position ,String * parameter_values){
	int number_value_parameter;
	
	number_value_parameter = recovery_number_from_next_value_parameter(parameter_values, actual_position);
	return is_valid_number(number_value_parameter);
}

int recovery_number_from_next_value_parameter(String * parameter_values, int actual_position){
	String next_parameter;
	
	next_parameter = get_next_parameter(parameter_values, actual_position);
	return convert_string_to_int(next_parameter);
}

int convert_string_to_int(String value){
	return atoi(value);
}

String get_next_parameter(String * parameter_values, int actual_position){
	return get_parameter(parameter_values, actual_position+1);
}

boolean is_valid_number(int value){
	return (value != 0);
}

void set_environment_configuration_from_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int number_value_parameter; // Number parameters, complements to definition_parameters
	String actual_definition_parameter; // Parameters like -d, -c, -i

	for(actual_position= initial_position; actual_position<parameter_count; actual_position++) {	
		actual_definition_parameter = get_parameter(parameter_values, actual_position);
		
		if(is_parameter_debug(actual_definition_parameter))
			set_debug(TRUE);
		else{
			number_value_parameter = recovery_number_from_next_value_parameter(parameter_values, actual_position);
			
			if(is_parameter_num_cicles(actual_definition_parameter))
				set_num_cicles(number_value_parameter);
			else if(is_parameter_num_instructions(actual_definition_parameter))
				set_num_instructions(number_value_parameter);
		}
	}
	
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

boolean is_parameter_num_cicles(String definition_parameter){
	return (are_equal_strings(definition_parameter, short_cicle) 
			|| are_equal_strings(definition_parameter, extensive_cicle));
}

boolean is_parameter_num_instructions(String definition_parameter){
	return (are_equal_strings(definition_parameter, short_instructions) 
			|| are_equal_strings(definition_parameter, extensive_instructions));
}

boolean is_parameter_debug(String definition_parameter){
	return (are_equal_strings(definition_parameter, short_debug) 
			|| are_equal_strings(definition_parameter, extensive_debug));
}

boolean are_equal_strings(String string1, String string2){
	return (strcmp(string1, string2) == 0);
}
