#ifndef DEBUG_H
#define DEBUG_H

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

void log_init_process_debug();

void log_init_generate_array_debug();

void log_init_write_on_binary_file();

void log_init_write_on_text_file();

void log_end_process_debug();

void log_end_generate_array_debug();

void log_end_write_on_binary_file();

void log_end_write_on_text_file();

#endif
