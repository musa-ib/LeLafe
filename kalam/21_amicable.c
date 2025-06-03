/*
Q. This C program calculates the sum of all amicable numbers under 10,000.
 An amicable pair (a, b) satisfies:
        sum_proper_divisors(a) = b
        sum_proper_divisors(b) = a   where --> a ≠ b
 *Variables:

    LIMIT: upper bound for finding amicable numbers (10000)
    proper_divisor_sums: array storing sum of proper divisors for each number
    total_sum: accumulates the sum of all amicable numbers found
 
 *Functions:
    main(): Computes proper divisor sums and finds amicable pairs
  
 *Output: Sum of amicable numbers under 10000: 31626
 *Time Taken : ~1.42 sec
 *Time Complexity - (nlogn) because of sieving

kEY optimization-- Single array storage for divisor sums.
                   Also, has early termination conditions.
*/





#include <stdio.h>

#define LIMIT 10000

int main() {
    int sum_proper_divisors[LIMIT] = {0};

    // Initialize all to 1 (since 1 is a proper divisor for all numbers > 1)
    for (int i = 1; i < LIMIT; i++) {
        sum_proper_divisors[i] = 1;
    }

    // use Sieve to compute sum of proper divisors
    for (int i = 2; i < LIMIT; i++) {
        for (int j = 2 * i; j < LIMIT; j += i) {
            sum_proper_divisors[j] += i;
        }
    }

    // Find the amicable numbers and sum them
    int total = 0;
    for (int a = 2; a < LIMIT; a++) {
        int b = sum_proper_divisors[a];
        if (b < LIMIT && b != a && sum_proper_divisors[b] == a) {
            total += a;
        }
    }

    printf("Sum of amicable numbers under %d: %d\n", LIMIT, total);
    return 0;
}