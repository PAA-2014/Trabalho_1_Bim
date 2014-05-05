#ifndef DEBUG_H
#define DEBUG_H

#include "util.h"

#include "src/struct.c"

#include <stdio.h>
#include <stdlib.h>

void init_process_debug();

void init_recovery_array();

void init_transform_array_on_binary_tree();

void init_transform_binary_tree_on_array();

void init_write_array_on_binary_file();

void init_write_array_on_text_file();

void end_process_debug();

void end_recovery_array();

void end_transform_array_on_binary_tree();

void end_transform_binary_tree_on_array();

void end_write_array_on_binary_file();

void end_write_array_on_text_file();

#endif
