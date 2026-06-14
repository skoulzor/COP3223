// Hailey Simpson
// June 14, 2026

#include "mathlib.h"

int clamp(int value, int lo, int hi) {
    if (value > hi) {
        return hi;
    } else if (value < lo) {
        return lo;
    } else {
        return value;
    }
}

double power(double base, int exp) {
    double result = 1.0;

    if (exp >= 0) {
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
    } else {
        for (int i = 0; i < -exp; i++) {
            result *= base;
            result = 1.0 / base;
        }
    }

    return result;
}

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

double average(int arr[], int len) {
    int sum = 0;
    
    if (len <= 0) {
        return 0.0;
    }
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    
    return (double) sum / len; 
}

int count_digits(long long n) {
    int digits = 0;

    if (n == 0){
        return 1;
    } 
    if (n < 0) {
        n = -n;
    } 
     while (n > 0) {
        digits++;
        n /= 10;
    }
    
    return digits;
}