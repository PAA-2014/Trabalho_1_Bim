#ifndef STRUCT_C
#define STRUCT_C

#include <time.h>

typedef enum enum_boolean {
FALSE, TRUE
} boolean;

typedef struct tp_cicle{
	clock_t start_time;
	clock_t end_time;
	double time_spent;
}cicle;

#endif
