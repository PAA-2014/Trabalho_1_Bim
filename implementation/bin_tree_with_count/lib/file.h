#ifndef FILE_H
#define FILE_H

#include "util.h"

#include "src/struct.c"

#include <stdio.h>
#include <stdlib.h>

void write_array_on_binary_file(String file_path, int * array, int amount_numbers);

void write_array_on_text_file(String file_path, int * array, int amount_numbers);

int * recovery_array_from_file(String file_path, int array_size);

int get_amount_numbers_of_file(String file_path, int size_of_type);

int get_bytes_in_file(String file_path);

inline void seek_end(FILE * file);

#endif
