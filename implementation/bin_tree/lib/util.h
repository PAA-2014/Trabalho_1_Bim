#ifndef UTIL_H
#define UTIL_H

#include "src/struct.c"

#include <math.h>
#include <string.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

String replace_last_char(String string_base, char to_remove, String to_put);

int get_last_pos_character(String string_base, char searched);

String get_before(String string_base, int position_to_cut);

String get_after(String string_base, int position_to_cut);

int string_lenght(String value);

String new_string(int size);

boolean are_equal_strings(String string1, String string2);

boolean is_valid_string(String value);

int convert_string_to_int(String value);

boolean is_valid(int value);

int convert_string_to_int(String value);

boolean is_valid_natural_number(int value);

int count_algarisms_from_number(unsigned int value);

String convert_int_to_string(int number);

int get_major_number_from_unsorted_array(int * array, int array_size);

int count_max_algarisms(int * random_array, int amount_numbers);

String generate_format_to_impress(int max_algarisms);

int * new_int_array(unsigned int size);

boolean is_end_of_line(int actual_number, int algarisms_per_number);

int numbers_to_write_per_line(int algarisms_per_number);

clock_t get_actual_time();

double calc_time(interval interval_time);

#endif
