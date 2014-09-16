#include "../parameter_checker.h"

#define STRING_TO_APPEND_AUX "-aux-output."
#define STRING_TO_APPEND "-output."
#define CHAR_TO_REMOVE '.'

#define minimum_number_parameters 3
#define initial_position 1
#define minimum_number_definition_parameters (minimum_number_parameters - initial_position) / 2
#define jump_to_next_definition_parameter() actual_position++

// Init of Definition Parameters
#define short_debug "-d"
#define extensive_debug "-debug"

#define short_file_path "-f"
#define extensive_file_path "-file-path"
// End of Definition Parameters

environment_configurations configurations;

boolean are_valid_parameters(int parameter_count, String * parameter_values){

	if(has_no_parameters(parameter_count)
		|| has_less_than_minimum_number_parameters(parameter_count)) {
		return FALSE;
	} else {
		return validate_parameters(parameter_count, parameter_values);
	}
}

boolean has_no_parameters(int parameter_count){

	return (parameter_count <= 1);
}

boolean has_less_than_minimum_number_parameters(int parameter_count){

	return (parameter_count < minimum_number_parameters);
}


boolean validate_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int count_mandatory_parameters;
	String actual_definition_parameter; // Parameters like -d, -c, -i
	
	count_mandatory_parameters = 0;
	
	for(actual_position= initial_position; actual_position< parameter_count; actual_position++ ){
		actual_definition_parameter = get_parameter(parameter_values, actual_position);

		if(is_not_valid_parameter(actual_definition_parameter))
			return FALSE;
		else
			if(is_flag_parameter(actual_definition_parameter))
				continue;
			else {
				if(validate_actual_parameter(actual_definition_parameter, actual_position, parameter_values))
					jump_to_next_definition_parameter();
				else
					return FALSE;
					
				if(is_mandatory_parameter(actual_definition_parameter))
					count_mandatory_parameters++;
			}	
	}
	
	if(count_mandatory_parameters != minimum_number_definition_parameters)
		return FALSE;
	else
		return TRUE;
}

boolean is_not_valid_parameter(String parameter){

	return !(is_optional_parameter(parameter)
			|| is_mandatory_parameter(parameter));
}

boolean validate_actual_parameter(String actual_definition_parameter, int actual_position, String * parameter_values){

	if(is_numeric_parameter(actual_definition_parameter))
		return is_valid_next_numeric_value_parameter(actual_position, parameter_values);
	else if (is_string_parameter(actual_definition_parameter))
		return is_valid_next_string_value_parameter(actual_position, parameter_values);
	else 
		return FALSE;
}

String get_parameter(String * parameter_values, int actual_position){

	return parameter_values[actual_position];
}

boolean is_optional_parameter(String definition_parameter){

	return (is_parameter_debug(definition_parameter));
}

boolean is_mandatory_parameter(String definition_parameter){

	return (is_parameter_file_path(definition_parameter));
}

boolean is_numeric_parameter(String definition_parameter){

	return FALSE;
}

boolean is_flag_parameter(String definition_parameter){

	return (is_parameter_debug(definition_parameter));
}

boolean is_string_parameter(String definition_parameter){

	return is_parameter_file_path(definition_parameter);
}

boolean is_valid_next_numeric_value_parameter(int actual_position ,String * parameter_values){

	int number_value_parameter;
	
	number_value_parameter = recovery_number_from_next_value_parameter(parameter_values, actual_position);
	return is_valid_number(number_value_parameter);
}

boolean is_valid_number(int value){

	return (value != 0);
}

int recovery_number_from_next_value_parameter(String * parameter_values, int actual_position){

	String next_parameter;
	
	next_parameter = get_next_parameter(parameter_values, actual_position);
	return convert_string_to_int(next_parameter);
}

boolean is_valid_next_string_value_parameter(int actual_position ,String * parameter_values){

	String string_value_parameter;
	
	string_value_parameter = recovery_string_from_next_value_parameter(parameter_values, actual_position);
	return is_valid_string(string_value_parameter);
}

String recovery_string_from_next_value_parameter(String * parameter_values, int actual_position){

	return get_next_parameter(parameter_values, actual_position);;
}

String get_next_parameter(String * parameter_values, int actual_position){

	return get_parameter(parameter_values, actual_position+1);
}

void set_environment_configuration_from_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int number_value_parameter; // Number parameters, complements to definition_parameters
	String string_value_parameter; // String parameters, complements to definition_parameters
	String actual_definition_parameter; // Parameters like -d, -c, -i
	
	log_init_optinional_parameters();

	for(actual_position= initial_position; actual_position<parameter_count; actual_position++) {
		actual_definition_parameter = get_parameter(parameter_values, actual_position);
		
		if(is_flag_parameter(actual_definition_parameter)){
			if(is_parameter_debug(actual_definition_parameter))
				set_debug(TRUE);
		} else {
			if(is_string_parameter(actual_definition_parameter)){
				string_value_parameter = recovery_string_from_next_value_parameter(parameter_values, actual_position);
				if(is_parameter_file_path(actual_definition_parameter)){
					set_file_path(string_value_parameter);
					set_aux_output_file_path(string_value_parameter);
					set_output_file_path(string_value_parameter);
				}
			}
			jump_to_next_definition_parameter();
		}
	}
}

void log_init_optinional_parameters(){

	set_debug(FALSE);
}

void set_file_path(String value){

	configurations.file_path = value;
}

void set_output_file_path(String value){

	configurations.output_file_path = replace_last_char(value,CHAR_TO_REMOVE,STRING_TO_APPEND);
}

void set_aux_output_file_path(String value){

	configurations.aux_output_file_path = replace_last_char(value,CHAR_TO_REMOVE,STRING_TO_APPEND_AUX);
}

void set_debug(int value){

	configurations.debug = value;
}

boolean is_parameter_file_path(String parameter){

	return (are_equal_strings(parameter, short_file_path)
			||are_equal_strings(parameter, extensive_file_path));
}

boolean is_parameter_debug(String parameter){

	return (are_equal_strings(parameter, short_debug)
			||are_equal_strings(parameter, extensive_debug));
}
