#ifndef PARAMETER_CHECKER_H
#define PARAMETER_CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "src/struct.c"

boolean are_valid_parameters(int parameter_count, String * parameter_values);

void set_environment_configuration_from_parameters(int parameter_count, String * parameter_values);

int recovery_number_from_next_quantitative_parameter(String * parameter_values, int actual_position);

void set_num_instructions(int value);

void set_num_cicles(int value);

void set_debug(boolean value);

boolean has_no_parameters(int parameter_count);

boolean is_parameter_num_cicles(String parameter);

boolean is_parameter_num_instructions(String parameter);

boolean is_parameter_debug(String parameter);

int convert_string_to_int(String value);

boolean is_valid_number(int value);

String get_parameter(String * parameter_values, int actual_position);

String get_next_parameter(String * parameter_values, int actual_position);

#endif
