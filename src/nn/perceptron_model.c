/* perceptron_model.c --- 
 * 
 * Filename: perceptron_model.c
 * Description: 
 * Author: Karthik Kumar
 * Maintainer: 
 * Created: Wed Jun 13 03:18:59 2018 (+0530)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Wed Jun 13 03:19:05 2018 (+0530)
 *           By: Karthik Kumar
 *     Update #: 1
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



/* perceptron_model.c ends here */
