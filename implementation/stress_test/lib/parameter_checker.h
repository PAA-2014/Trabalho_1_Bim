#ifndef PARAMETER_CHECKER_H
#define PARAMETER_CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "src/struct.c"

boolean are_valid_parameters(int parameter_count, String * parameter_values);

boolean has_no_parameters(int parameter_count);

boolean validate_parameters(int parameter_count, String * parameter_values);

String get_parameter(String * parameter_values, int actual_position);

boolean is_optional_parameter(String definition_parameter);

boolean is_mandatory_parameter(String definition_parameter);

boolean is_valid_next_value_parameter(int actual_position ,String * parameter_values);

int recovery_number_from_next_value_parameter(String * parameter_values, int actual_position);

int convert_string_to_int(String value);

String get_next_parameter(String * parameter_values, int actual_position);

boolean is_valid_number(int value);

void set_environment_configuration_from_parameters(int parameter_count, String * parameter_values);

void set_num_instructions(int value);

void set_num_cicles(int value);

void set_debug(boolean value);

boolean is_parameter_num_cicles(String definition_parameter);

boolean is_parameter_num_instructions(String definition_parameter);

boolean is_parameter_debug(String definition_parameter);

boolean are_equal_strings(String string1, String string2);

#endif
