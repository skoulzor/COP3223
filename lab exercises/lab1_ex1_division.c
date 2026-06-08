#include <stdio.h>

int main(void) {

    printf("7 / 2 = %d\n", 7 / 2);
    printf("7.0 / 2 = %.6f\n", 7.0 / 2);
    printf("7 / 2.0 = %.6f\n", 7 / 2.0);
    printf("(double)7 / 2 = %lf\n", (double)7 / 2);
    printf("(double)(7 / 2) = %lf\n", (double)(7 / 2));
    printf("7 %% 2 = %d\n", 7 % 2);
    printf("-7 / 2 = %d\n", -7 / 2);
    printf("-7 %% 2 = %d\n", -7 % 2);

    /* Table
    
    Expression	        Your Prediction	    Actual Result
    7 / 2		        3                   3
    7.0 / 2		        3.5                 3.500000
    7 / 2.0		        3.5                 3.500000
    (double)7 / 2	    3.5	                3.500000
    (double)(7 / 2)	    3.0	                3.000000
    7 % 2		        1                   1
    -7 / 2		        -3                  -3
    -7 % 2              -1                  -1
    
    */

    /* Checkpoint Questions

    1. What is the difference between (double)7 / 2 and (double)(7 / 2)?
    (double)7 / 2: Convert 7 to 7.0 first, then divide. Result: 3.5.
    (double)(7 / 2): Divide 7 by 2 as integers first. 7 / 2 = 3, then convert to 3.0. Result: 3.0.

    2. What is the sign of a % b when a is negative?
    If a is negative, a % b has the same sign as a. Example: -7 % 3 = -1.

    3. How would you compute the percentage of correct answers if correct and total are both int?
    Cast to double before dividing.

    */
}