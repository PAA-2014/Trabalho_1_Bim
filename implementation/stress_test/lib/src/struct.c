#ifndef STRUCT_C
#define STRUCT_C

#include <time.h>

#define String char *

typedef enum enum_boolean {
FALSE, TRUE
} boolean;

typedef struct tp_cicle{
	clock_t start_time;
	clock_t end_time;
	double time_spent;
}cicle;

typedef struct tp_environment_configurations{
	int long long num_instructions;
	int long long num_cicles;
	boolean debug;
}environment_configurations;

#endif
