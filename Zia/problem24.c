//What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
#include <stdio.h>

#define N 10

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    int digits[N] = {0,1,2,3,4,5,6,7,8,9};
    int target = 10;
    int result[N];
    int length = N;

    // Precompute factorials (optional optimization)
    int fact[N];
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
    }

    target -= 1;  // zero-based index

    for (int i = 0; i < length; i++) {
        int f = fact[length - 1 - i];
        int index = target / f;
        target = target % f;

        result[i] = digits[index];

        // Remove digits[index] from digits array
        for (int j = index; j < length - 1 - i; j++) {
            digits[j] = digits[j + 1];
        }
    }

    printf("Millionth lexicographic permutation is: ");
    for (int i = 0; i < length; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    return 0;
}
