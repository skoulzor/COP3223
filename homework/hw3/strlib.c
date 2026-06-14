// Hailey Simpson
// June 14, 2026

#include "strlib.h"

int str_length(const char *s) {
    /* TODO: walk s with a pointer until '\0', count steps */
    int count = 0;

    while (*s != '\0') {
        count++;
        s++;
    }

    return count;
}

void str_copy(char *dst, const char *src, int dst_size) {
    /* TODO: copy characters one at a time, stop at dst_size-1 or '\0' */
    /* Always null-terminate dst */
    if (dst_size <= 0) {
        return;
    }

    int i = 0;

    while (*src != '\0' && i < dst_size - 1) {
        *dst = *src;
        dst++;
        src++;
        i++;
    }

    *dst = '\0';
}

int str_compare(const char *a, const char *b) {
    /* TODO: walk both strings simultaneously, return first difference */
     while (*a != '\0' && *b != '\0' && *a == *b) {
        a++;
        b++;
    }

    return *a - *b;
}

void str_reverse(char *s) {
    /* TODO: swap characters from both ends toward the middle */
    char *left = s;
    char *right = s + str_length(s) - 1;

    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int str_count_char(const char *s, char c) {
    /* TODO: return the number of times character c appears in s */
    int count = 0;

    while (*s != '\0') {
        if (*s == c) {
            count++;
        }
        s++;
    }

    return count;
}

void str_to_upper(char *s) {
    /* TODO: for each char, if 'a' <= c <= 'z', subtract 32 */
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            *s = *s - ('a' - 'A');
        }
        s++;
    }
}

void array_stats(const int arr[], int len,
                 int *out_min, int *out_max, double *out_avg) {
    /* TODO: handle len <= 0 case; otherwise scan for min/max/sum */
        if (len <= 0) {
        *out_min = 0;
        *out_max = 0;
        *out_avg = 0.0;
        return;
    }

    int min = arr[0];
    int max = arr[0];
    int sum = arr[0];

    for (int i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }

    *out_min = min;
    *out_max = max;
    *out_avg = (double)sum / len;
}

int array_find(const int arr[], int len, int target) {
    /* TODO: linear scan; return index or -1 */
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}