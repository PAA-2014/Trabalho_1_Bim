#ifndef STRESS_TEST_H
#define STRESS_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "src/struct.c"

// Init of Get Functions
clock_t get_actual_time();

cicle ** new_cicle_array(int long long num_cicles);

cicle * new_cicle();
// End of Get Functions

// Init of Calculate Functions
double calculate_total_time(cicle ** cicles, int long long num_cicles);

double calculate_time_spent(cicle * actual_cicle);

double calculate_avarage_time(double total_time, int long long num_cicles);

double calculate_instructions_per_seccond(int long long num_instructions, double avarage_time );
// End of Calculate Functions

// Execute Functions
void execute_stress_test();

void execute_cicle_test(cicle * actual_cicle, int long long num_instructions);

inline void execute_instructions_per_seccond_test(int long long num_instructions);
// Enf of Execute Functions

// Init of Print Functions
void print_debug(int pos_cicle, cicle * actual_cicle);

void print_results(double avarage_time, double instructions_per_seccond);
// Enf of Print Functions

#endif
