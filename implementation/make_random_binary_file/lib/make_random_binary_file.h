#ifndef MAKE_RANDOM_BINARY_FILE_H
#define MAKE_RANDOM_BINARY_FILE_H

#include "src/struct.c"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void make_random_binary_file();

void write_random_array_on_binary_file(String file_path, int * random_array, int amount_numbers);

inline void set_seeder(int seeder);

int * make_random_array(int amount_numbers, int bottom_limit, int top_limit);

int * new_int_array(unsigned int size);

int get_next_random_number(int bottom_limit, int top_limit);

boolean is_valid(int limit);

int limit_random_number(unsigned int random_number, int bottom_limit, int top_limit);

int limit_random_top(int random_number, int bottom_top);

int limit_random_bottom(int random_number, int bottom_limit);

#endif
