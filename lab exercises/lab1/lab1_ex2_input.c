#include <stdio.h>

int main(void) {
    int age; 
    char initial; 
    double decimal; 

    do {
        printf("Enter your age (1-120): ");
        fscanf(stdin, "%d", &age);

        if (age < 1 || age > 120) {
            printf("Invalid input. Try again.\n");
        }
    } while(age < 1 || age > 120);

    do {
        printf("Enter your initial (A-Z): ");
        fscanf(stdin, " %c", &initial);

        if (!((initial >= 'A' && initial <= 'Z') || (initial >= 'a' && initial <= 'z'))) {
            printf("Invalid input. Try again.\n");
        }
    } while(!((initial >= 'A' && initial <= 'Z') || (initial >= 'a' && initial <= 'z')));
    
    do {
        printf("Enter a positive decimal: ");
        fscanf(stdin, "%lf", &decimal);

        if (decimal <= 0.0) {
            printf("Invalid input. Try again.\n");
        }
    } while(decimal <= 0.0);

    printf("Hello, %c. You are %d years old. Your number: %.2lf\n",
           initial, age, decimal);

    return 0;

    /* Checkpoint Questions
   
    1. Why does reading a char after an int with scanf often read \n?
    When you enter an integer and press Enter, the newline character ('\n') is also stored in the input buffer. 
    The %d conversion reads only the digits of the integer and leaves the newline behind. 
    When %c is used next, it reads the leftover newline character instead of waiting for a new character from the user. 

    2. What does the trailing space in fscanf(stdin, "%d ", &age) do?
    The space after %d tells fscanf to skip any whitespace characters that follow the integer. This includes spaces, tabs, and newlines. 
    As a result, the program may wait for additional input because it keeps looking for a non-whitespace character before continuing.
    
    3. Could you use while instead of do-while here? What would change?
    Yes, you can use a while loop instead of a do-while loop. 
    The difference is that a while loop checks its condition before executing the loop body, while a do-while loop checks its condition after executing the loop body. 
    For input validation, do-while is often more convenient because it guarantees that the user is prompted at least once.
    
    */
}