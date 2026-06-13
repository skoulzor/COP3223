#include <stdio.h>

int main(void) {
    char name[64];
    int scores[5];
    float average;
    int sum = 0;
    int highest, lowest;
    char grade;

    printf("Enter student name: ");
    fscanf(stdin, "%63s", name);

    for (int i = 0; i < 5; i++) {
        do {
            printf("Enter score %d (0-100): ", i + 1);
            fscanf(stdin, "%d", &scores[i]);

            if (scores[i] < 0 || scores[i] > 100) {
                printf("Invalid input. Try again.\n");
            }
        } while (scores[i] < 0 || scores[i] > 100);

        sum += scores[i];

        if (i == 0) {
            highest = lowest = scores[i];
        } else {
            if (scores[i] > highest) {
                highest = scores[i];
            }
            if (scores[i] < lowest) {
                lowest = scores[i];
            }
        } 
    }

    average = sum / 5.0;

    switch ((int)(average / 10)) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
    }

    printf("\n= Grade Report =\n");
    printf("Student:\t%s\n", name);

    printf("Scores:\t\t");
    for (int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    printf("Average:\t%.2f\n", average);
    printf("Grade:\t\t%c\n", grade);

}