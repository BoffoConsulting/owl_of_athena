/* perceptron.c --- 
 * 
 * Filename: perceptron.c
 * Description: 
 * Author: Karthik Kumar
 * Maintainer: 
 * Created: Sun Apr 29 21:34:12 2018 (+0530)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Sat Jun  2 14:37:11 2018 (+0530)
 *           By: Karthik Kumar
 *     Update #: 53
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <https://www.gnu.org/licenses/>.
 */

/* Code: */


/* Header Files */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


/* Macros */
#define LEARNING_RATE 0.1
#define TRUTH_TABLE_INPUTS 2
#define RANDOM_RANGE(max) (rand() % max)
#define BIAS -1
#define CYCLES 100



/* Global Variables */
int correct = 0;
int incorrect = 0;
int train_for = 10000;



/*
 * Perceptron structure with learning rate, weights,
 * bias, output and guess
 */
typedef struct _perceptron {
	double weights[TRUTH_TABLE_INPUTS];
	double learning_rate;
	double bias;
	int output;
	int guess;
} PERCEPTRON;


/* 
 * Training Truth Table - OR Gate 
 */
typedef struct _or_gate {
	double inputs[TRUTH_TABLE_INPUTS];
	double result;
} OR_GATE;


/* 
 * Training Truth Table - AND Gate 
 */
typedef struct _and_gate {
	double inputs[TRUTH_TABLE_INPUTS];
	double result;
} AND_GATE;


/* 
 * OR_GATE Truth table 
 */
OR_GATE or_gate[] = {
	{{0, 0}, 0},
	{{0, 1}, 1},
	{{1, 0}, 1},
	{{1, 1}, 1},
};


/* 
 * AND_GATE Truth table 
 */
AND_GATE and_gate[] = {
	{{0, 0}, 0},
	{{0, 1}, 0},
	{{1, 0}, 0},
	{{1, 1}, 1},
};


/* 
 * Function Prototypes 
 */
double random_double();
int activation_function(double n);
void train(double error, double inputs[], int n);


/* 
 * Returns random double value
 */
double
random_double()
{
	return (double) rand() / (double) RAND_MAX;
}


/*
 * Function check for activation
 */
int
activation_function(double n)
{
	if ((n - 1.5) < 0)
		return 0;
	return 1;
}


/* 
 * Function trains the neural net (Perceptron)
 */
void
train(double error, double inputs[], int n)
{
	for (int i = 0; i < n; i++) {
		
	}

}


/* Main Function */
int main(int argc, char *argv[])
{
	srand(time(NULL));
	PERCEPTRON p_or;
	printf("Random value: %d\n", RANDOM_RANGE(4));	
	
	return 0;
}

/* perceptron.c ends here */
