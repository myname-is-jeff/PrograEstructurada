#include <stdio.h>
#include <stdlib.h>

#define EQMASK 3
typedef enum{
	EQUIALIZATION_FLAT = 0,
	EQUIALIZATION_POP = 1,
	EQUIALIZATION_ROCK = 2,
	EQUIALIZATION_CLASSIC = 3,
} equalization_t;

