

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


#define LEARNING_RATE 0.05
#define MAX_ITERATION 100

time_t t;

/* Function Prototype */
float random_value()
{
	return (float) rand() / (float)RAND_MAX;
}



int main(int argc, char *argv[])
{
	srand((unsigned) time(&t));
	printf("Random Value: %f\n", random_value());

	printf("rand(): %f\n", (float)rand());
	printf("RAND_MAX: %f\n", (float)RAND_MAX);
	printf("time_t: %ld\n", t);
	
	return 0;
}
