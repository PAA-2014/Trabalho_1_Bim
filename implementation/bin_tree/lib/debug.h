#ifndef DEBUG_H
#define DEBUG_H

#include "util.h"

#include "src/struct.c"

#include <stdio.h>
#include <stdlib.h>

void log_init_process_debug();

void log_init_recovery_array();

void log_init_transform_array_on_binary_tree();

void log_init_transform_binary_tree_on_array();

void log_init_write_array_on_binary_file();

void log_init_write_array_on_text_file();

void log_end_process_debug();

void log_end_recovery_array();

void log_end_transform_array_on_binary_tree();

void log_end_transform_binary_tree_on_array();

void log_end_write_array_on_binary_file();

void log_end_write_array_on_text_file();

#endif
