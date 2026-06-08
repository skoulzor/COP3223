#include <stdio.h>

int main(void) {
    printf("\n--- Prediction ---\n");
    printf("7 / 2 = 3\n");
    printf("7.0 / 2 = 3.5\n");
    printf("7 / 2.0 = 3.5\n");
    printf("(double)7 / 2 = 3.5\n");
    printf("(double)(7 / 2) = 3.5\n");
    printf("7 %% 2 = 1\n");
    printf("-7 / 2 = -3\n");
    printf("-7 %% 2 = -1\n");

    printf("\n--- Actual ---\n");
    printf("7 / 2 = %d\n", 7 / 2);
    printf("7.0 / 2 = %.6f\n", 7.0 / 2);
    printf("7 / 2.0 = %.6f\n", 7 / 2.0);
    printf("(double)7 / 2 = %lf\n", (double)7 / 2);
    printf("(double)(7 / 2) = %lf\n", (double)(7 / 2));
    printf("7 %% 2 = %d\n", 7 % 2);
    printf("-7 / 2 = %d\n", -7 / 2);
    printf("-7 %% 2 = %d\n", -7 % 2);
}