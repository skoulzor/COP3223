// Hailey Simpson
// June 14, 2026

#include <stdio.h>
#include "strlib.h"

#define MAX_STR 256
#define MAX_ARR 100

void do_length(void);
void do_copy(void);
void do_compare(void);
void do_reverse(void);
void do_count(void);
void do_upper(void);
void do_stats(void);
void do_find(void);

int main(void) {
    int choice;

    do {
        printf("\n= String & Array Toolkit =\n");
        printf("1. String length\n");
        printf("2. String copy (with truncation demo)\n");
        printf("3. String compare\n");
        printf("4. Reverse a string\n");
        printf("5. Count a character\n");
        printf("6. Convert to uppercase\n");
        printf("7. Array stats (min/max/avg)\n");
        printf("8. Find value in array\n");
        printf("9. Quit\n");

        do {
            printf("Enter choice (1-9): ");
            fscanf(stdin, "%d", &choice);

            if (choice < 1 || choice > 9) {
                printf("Invalid choice. Try again.\n");
            }
        } while (choice < 1 || choice > 9);

        switch (choice) {
            case 1: do_length(); break;
            case 2: do_copy(); break;
            case 3: do_compare(); break;
            case 4: do_reverse(); break;
            case 5: do_count(); break;
            case 6: do_upper(); break;
            case 7: do_stats(); break;
            case 8: do_find(); break;
            case 9: printf("Goodbye!\n"); break;
        }

    } while (choice != 9);

    return 0;
}

void do_length(void) {
    char s[MAX_STR];

    printf("Enter string: ");
    fscanf(stdin, " %[^\n]", s);

    printf("Length: %d\n", str_length(s));
}

void do_copy(void) {
    char src[MAX_STR];
    char dst[8];

    printf("Enter string: ");
    fscanf(stdin, " %[^\n]", src);

    str_copy(dst, src, sizeof(dst));

    printf("Copied: %s\n", dst);
}

void do_compare(void) {
    char a[MAX_STR], b[MAX_STR];

    printf("Enter first string: ");
    fscanf(stdin, " %[^\n]", a);

    printf("Enter second string: ");
    fscanf(stdin, " %[^\n]", b);

    int r = str_compare(a, b);

    if (r < 0)
        printf("%s comes before %s\n", a, b);
    else if (r == 0)
        printf("%s equals %s\n", a, b);
    else
        printf("%s comes after %s\n", a, b);
}

void do_reverse(void) {
    char s[MAX_STR];

    printf("Enter string: ");
    fscanf(stdin, " %[^\n]", s);

    str_reverse(s);

    printf("Reversed: %s\n", s);
}

void do_count(void) {
    char s[MAX_STR];
    char c;

    printf("Enter string: ");
    fscanf(stdin, " %[^\n]", s);

    printf("Enter character: ");
    fscanf(stdin, " %c", &c);

    printf("Count: %d\n", str_count_char(s, c));
}

void do_upper(void) {
    char s[MAX_STR];

    printf("Enter string: ");
    fscanf(stdin, " %[^\n]", s);

    str_to_upper(s);

    printf("Upper: %s\n", s);
}

void do_stats(void) {
    int arr[MAX_ARR];
    int len;
    int min, max;
    double avg;

    printf("Enter count then values: ");
    fscanf(stdin, "%d", &len);

    for (int i = 0; i < len; i++) {
        fscanf(stdin, "%d", &arr[i]);
    }

    array_stats(arr, len, &min, &max, &avg);

    printf("min=%d max=%d avg=%.2f\n", min, max, avg);
}

void do_find(void) {
    int arr[MAX_ARR];
    int len, target;

    printf("Enter count then values: ");
    fscanf(stdin, "%d", &len);

    for (int i = 0; i < len; i++) {
        fscanf(stdin, "%d", &arr[i]);
    }

    printf("Enter target: ");
    fscanf(stdin, "%d", &target);

    int idx = array_find(arr, len, target);

    if (idx >= 0)
        printf("Found at index %d.\n", idx);
    else
        printf("Not found.\n");
}