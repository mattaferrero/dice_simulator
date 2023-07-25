/* 
* This program is designed to simulate rolls of six-sided dice (referred to as d6's) and display things
* such as variance, probability curves and common percentile charts. This program is meant to be used
* as an exercise for the author to become more familiar with writing simulation software. Although accuracy
* is strived for, it is not guaranteed or even expected. 
* 
* This software is not designed to be comprehensive or even useful, let alone in an academic setting. Use it at your own risk.
*
* M. Ferrero
*/

#define ARRAY_SIZE  6
#define DIE_SIM     6                           /* For a d12 just change to 12, d10 to 10 etc. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

int percent_rolls(void);                        /* A test function to continuously output the integer number and % of each die roll value in a display. */

int main(int arcg, char **argv) {

    percent_rolls();
    
    return 0;
}

/* This is probably the absolute _least_ elegant method to get nice-looking output, but I only care about the results frankly. */
int percent_rolls(void) {

    int ctr = 0;
    uint64_t num_rolls = 0;                     /* Total number of die rolls or "simulations". */
    uint64_t num_rolled = 0;                    /* rand()'s output. */
    uint64_t dieface_ctr[ARRAY_SIZE] = {0};     /* This represents how many times each number on a d6 has been rolled. [0] = 1 has been rolled, [1] = 2 has been rolled etc. */

    srand(time(NULL));                          /* Apparently this is necessary to sufficiently randomize rand(). How very meta. */

    while (1) {

        /* This formula is meant to remove the rand() bias essentially by limiting it's output to the range we set and ensuring even distribution. */
        /* We're using floor to round down to the nearest whole integer. Adding 1 ensures we are within the correct range of DIE_SIM. */
        num_rolled = ( rand()/((RAND_MAX/(DIE_SIM)) + 1) );
        dieface_ctr[num_rolled]++, num_rolls++;
                     
        if (num_rolls % 100000 == 0) {          /* Only print every 100k rolls. */

            for (ctr = 0;ctr < ARRAY_SIZE;ctr++) { 
                fprintf(stdout, "%'llu's have been rolled %'llu times. Percentage output %f percent\n\r", ctr+1, dieface_ctr[ctr], ((float)dieface_ctr[ctr]/num_rolls)*100);
            }
        }

    }

    return 0;
}


    
    