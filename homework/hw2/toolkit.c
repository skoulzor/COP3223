// Hailey Simpson
// June 14, 2026

#include <stdio.h> 
#include "mathlib.h"

void handle_clamp(void);
void handle_power(void);
void handle_prime(void);
void handle_gcd(void);
void handle_average(void);
void handle_digits(void);

int main(void) {
    int choice;
    do {
        printf("= Math Toolkit =\n");
        printf("1. Clamp a value\n");
        printf("2. Compute a power\n");
        printf("3. Prime check\n");
        printf("4. GCD\n");
        printf("5. Array average\n");
        printf("6. Count digits\n");
        printf("7. Quit\n");

        do {
            printf("Enter choice (1-7): ");
            fscanf(stdin, "%d", &choice);

            if (choice < 1 || choice > 7) {
                printf("Invalid choice. Try again.\n\n");
            }
        } while (choice < 1 || choice > 7);
        
        switch (choice) {
            case 1: handle_clamp();   break;
            case 2: handle_power();   break;
            case 3: handle_prime();   break;
            case 4: handle_gcd();     break;
            case 5: handle_average(); break;
            case 6: handle_digits();  break;
            case 7: printf("Goodbye!\n"); break;
        } 
    } while (choice != 7);

    return 0;
}

void handle_clamp(void) {
    int value, lo, hi;

    printf("Enter value, lo hi: ");
    fscanf(stdin, "%d %d %d", &value, &lo, &hi);

    printf("clamp(%d, %d, %d) = %d\n\n", value, lo, hi, clamp(value, lo, hi));
}

void handle_power(void) {
    double base;
    int exp;

    printf("Enter base and exponent: ");
    fscanf(stdin, "%lf %d", &base, &exp);

    printf("power(%.2f, %d) = %.2f\n\n", base, exp, power(base, exp));
}

void handle_prime(void) {
    int n;
    
    printf("Enter n: ");
    fscanf(stdin, "%d", &n);

    if (is_prime(n))
        printf("%d is prime.\n\n", n);
    else
        printf("%d is not prime.\n\n", n);
}

void handle_gcd(void) {
    int a, b;

    printf("Enter a and b: ");
    fscanf(stdin, "%d %d", &a, &b);

    printf("gcd(%d, %d) = %d\n\n", a, b, gcd(a, b));
}

void handle_average(void) {
    int count;
    int arr[100];

    printf("Enter count then values: ");
    fscanf(stdin, "%d", &count);

    for (int i = 0; i < count; i++) {
        fscanf(stdin, "%d", &arr[i]);
    }

    printf("average = %.2f\n\n", average(arr, count));
}

void handle_digits(void) {
    long long n;

    printf("Enter integer: ");
    fscanf(stdin, "%lld", &n);

    printf("%lld has %d digits.\n\n", n, count_digits(n));
}

