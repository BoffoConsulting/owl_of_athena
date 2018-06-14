/* logical_neural_network.c --- 
 * 
 * Filename: logical_neural_network.c
 * Description: Program imitates results of logical operations AND / OR
 * Author: Karthik Kumar
 * Maintainer: Karthik Kumar
 * Created: Sun Apr 29 20:49:00 2018 (+0530)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Fri May  4 13:06:00 2018 (+0530)
 *           By: Karthik Kumar
 *     Update #: 49
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


/* Global Variables */
typedef struct _neuron {
	double weight; 
} NEURON;


typedef struct _layer {
	int size;
	NEURON *n;
} LAYER;


typedef struct _network {
    int inputs, layers, ouputs;
	LAYER *l;
} NETWORK;


/* Standalone Perceptron */
typedef struct _perceptron {
	double weights[2];
	double learning_rate = 0.01;
	double bias = -1;
} PERCEPTRON;




/* Training Truth Table - OR Gate */
typedef struct _or_gate {
	double inputs[TRUTH_TABLE_INPUTS];
	double result;
} OR_GATE;


/* Training Truth Table - AND Gate */
typedef struct _and_gate {
	double inputs[TRUTH_TABLE_INPUTS];
	double result;
} AND_GATE;





/* OR_GATE Truth table */
OR_GATE or_gate[] = {
	{{0, 0}, 0},
	{{0, 1}, 1},
	{{1, 0}, 1},
	{{1, 1}, 1},
};


/* AND_GATE Truth table */
AND_GATE and_gate[] = {
	{{0, 0}, 0},
	{{0, 1}, 0},
	{{1, 0}, 0},
	{{1, 1}, 1},
};



/* Function Prototypes */
double random_double();
NETWORK *create_network(int inputs, int layers, int outputs);



/* 
 * Returns random double value
 */
double
random_double()
{
	return (double) rand() / (double) RAND_MAX;
}


/* 
 * Creates a neural network
 * 
 * Arguments: 
 *   inputs: No of input nodes
 *   layers: No of layers in the entire network
 *   outputs: No of output nodes
 */
NETWORK
*create_network(int inputs, int layers, int outputs)
{
	NETWORK *nw = (NETWORK *) malloc(sizeof(NETWORK));
	nw->layers = layers;
	nw->inputs = inputs;
	nw->ouputs = outputs;	
	
	return nw;
}





int main(int argc, char *argv[])
{
	srand(time(NULL));
	PERCEPTRON *p = (PERCEPTRON *) malloc(sizeof(PERCEPTRON)); 
	double inputs[2];
	int train_for = 10000;
	
	
	return 0;
}

/* logical_neural_network.c ends here */
