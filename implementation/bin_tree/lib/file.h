#ifndef FILE_H
#define FILE_H

#include "src/struct.c"
#include <stdio.h>
#include <stdlib.h>

int get_bytes_in_file(String file_path);

inline void seek_end(FILE * file);

int get_amount_numbers_of_file(String file_path, int size_of_type);

int * recovery_array_from_file(String file_path, int array_size);

#endif
