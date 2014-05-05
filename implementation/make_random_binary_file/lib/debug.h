#ifndef DEBUG_H
#define DEBUG_H

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

void init_process_debug();

void init_generate_array_debug();

void init_write_on_binary_file();

void init_write_on_text_file();

void end_process_debug();

void end_generate_array_debug();

void end_write_on_binary_file();

void end_write_on_text_file();

#endif
