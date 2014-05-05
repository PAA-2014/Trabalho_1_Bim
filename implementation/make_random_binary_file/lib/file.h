#ifndef FILE_H
#define FILE_H

#include "util.h"

#include "src/struct.c"

#include <stdio.h>

void write_array_on_binary_file(String file_path, int * array, int amount_numbers);

void write_array_on_text_file(String file_path, int * array, int amount_numbers);

#endif
