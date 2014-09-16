#include "../parameter_checker.h"

#define STRING_TO_APPEND "-aux."
#define CHAR_TO_REMOVE '.'

#define MINIMUM_NUMBER_PARAMETERS 5
#define INITIAL_POSITION 1
#define MINIMUM_NUMBER_DEFINITION_PARAMETERS (MINIMUM_NUMBER_PARAMETERS - INITIAL_POSITION) / 2
#define JUMP_TO_NEXT_DEFINITION_PARAMETER actual_position++

// Init of Definition Parameters
#define SHORT_TOP_LIMIT "-t"
#define EXTENSIVE_TOP_LIMIT "-top-limit"

#define SHORT_BOTTOM_LIMIT "-b"
#define EXTENSIVE_BOTTOM_LIMIT "-bottom-limit"

#define SHORT_SEEDER "-s"
#define EXTENSIVE_SEEDER "-seeder"

#define SHORT_AMOUNT_NUMBERS "-a"
#define EXTENSIVE_AMOUNT_NUMBERS "-amount-numbers"

#define SHORT_DEBUG "-d"
#define EXTENSIVE_DEBUG "-debug"

#define SHORT_FILE_PATH "-f"
#define EXTENSIVE_FILE_PATH "-file-path"
// End of Definition Parameters

environment_configurations configurations;

boolean are_valid_parameters(int parameter_count, String * parameter_values){

	if(has_no_parameters(parameter_count) || (parameter_count < MINIMUM_NUMBER_PARAMETERS) )
		return FALSE;

	else
		return validate_parameters(parameter_count, parameter_values);
}

boolean has_no_parameters(int parameter_count){

	return (parameter_count <= 1);
}

boolean validate_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int count_mandatory_parameters;
	String actual_definition_parameter; // Parameters like -d, -c, -i
	
	count_mandatory_parameters = 0;
	
	for(actual_position= INITIAL_POSITION; actual_position< parameter_count; actual_position++ ){

		actual_definition_parameter = get_parameter(parameter_values, actual_position);

		if(is_not_valid_parameter(actual_definition_parameter))
			return FALSE;
		else
			if(is_flag_parameter(actual_definition_parameter))
				continue;
			else {
				if(validate_actual_parameter(actual_definition_parameter, actual_position, parameter_values))
					JUMP_TO_NEXT_DEFINITION_PARAMETER;
				else
					return FALSE;
					
				if(is_mandatory_parameter(actual_definition_parameter))
					count_mandatory_parameters++;
			}	
	}
	
	if(count_mandatory_parameters != MINIMUM_NUMBER_DEFINITION_PARAMETERS)
		return FALSE;
	else
		return TRUE;
}

void set_environment_configuration_from_parameters(int parameter_count, String * parameter_values){

	int actual_position; // Be ware of the #define
	int number_value_parameter; // Number parameters, complements to definition_parameters
	String string_value_parameter; // String parameters, complements to definition_parameters
	String actual_definition_parameter; // Parameters like -d, -c, -i
	
	log_init_optinional_parameters();

	for(actual_position= INITIAL_POSITION; actual_position<parameter_count; actual_position++) {
		actual_definition_parameter = get_parameter(parameter_values, actual_position);
		
		if(is_flag_parameter(actual_definition_parameter)){

			if(is_parameter_debug(actual_definition_parameter))
				set_debug(TRUE);
		} else {
			if(is_numeric_parameter(actual_definition_parameter)){

				number_value_parameter = recovery_number_from_next_value_parameter(parameter_values, actual_position);
			
				if(is_parameter_amount_numbers(actual_definition_parameter))
					set_amount_numbers(number_value_parameter);
				else if(is_parameter_bottom_limit(actual_definition_parameter))
					set_bottom_limit(number_value_parameter);
				else if(is_parameter_top_limit(actual_definition_parameter))
					set_top_limit(number_value_parameter);
				else if(is_parameter_seeder(actual_definition_parameter))
					set_seeder(number_value_parameter);
			} else if(is_string_parameter(actual_definition_parameter)){

				string_value_parameter = recovery_string_from_next_value_parameter(parameter_values, actual_position);
				if(is_parameter_file_path(actual_definition_parameter)){

					set_file_path(string_value_parameter);
					set_aux_file_path(string_value_parameter);
				}
			}
			JUMP_TO_NEXT_DEFINITION_PARAMETER;
		}
	}
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

	return (is_parameter_debug(definition_parameter)
			|| is_parameter_bottom_limit(definition_parameter)
			|| is_parameter_top_limit(definition_parameter)
			|| is_parameter_seeder(definition_parameter));
}

boolean is_mandatory_parameter(String definition_parameter){

	return (is_parameter_amount_numbers(definition_parameter)
			|| is_parameter_file_path(definition_parameter));
}

boolean is_numeric_parameter(String definition_parameter){

	return (is_parameter_bottom_limit(definition_parameter)
			|| is_parameter_top_limit(definition_parameter)
			|| is_parameter_seeder(definition_parameter)
			|| is_parameter_amount_numbers(definition_parameter));
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
	return is_valid(number_value_parameter);
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

void log_init_optinional_parameters(){

	set_top_limit(0);
	set_bottom_limit(0);
	set_debug(FALSE);
	set_seeder(0);
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

void set_file_path(String value){

	configurations.file_path = value;
}

void set_aux_file_path(String value){

	configurations.aux_file_path = replace_last_char(value,CHAR_TO_REMOVE,STRING_TO_APPEND);
}

void set_debug(int value){

	configurations.debug = value;
}

boolean is_parameter_top_limit(String parameter){

	return (are_equal_strings(parameter, SHORT_TOP_LIMIT)
			||are_equal_strings(parameter, EXTENSIVE_TOP_LIMIT));
}

boolean is_parameter_bottom_limit(String parameter){

	return (are_equal_strings(parameter, SHORT_BOTTOM_LIMIT)
			||are_equal_strings(parameter, EXTENSIVE_BOTTOM_LIMIT));
}

boolean is_parameter_seeder(String parameter){

	return (are_equal_strings(parameter, SHORT_SEEDER)
			||are_equal_strings(parameter, EXTENSIVE_SEEDER));
}

boolean is_parameter_amount_numbers(String parameter){

	return (are_equal_strings(parameter, SHORT_AMOUNT_NUMBERS)
			||are_equal_strings(parameter, EXTENSIVE_AMOUNT_NUMBERS));
}

boolean is_parameter_file_path(String parameter){

	return (are_equal_strings(parameter, SHORT_FILE_PATH)
			||are_equal_strings(parameter, EXTENSIVE_FILE_PATH));
}

boolean is_parameter_debug(String parameter){

	return (are_equal_strings(parameter, SHORT_DEBUG)
			||are_equal_strings(parameter, EXTENSIVE_DEBUG));
}

boolean validate_environment_configurations(){

	return (configurations.bottom_limit <= configurations.top_limit
			&& is_valid_natural_number(configurations.amount_numbers));
}
