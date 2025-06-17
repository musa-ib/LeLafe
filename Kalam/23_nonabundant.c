/*Problem
Program to calculate the sum of all positive integers which cannot be writtenc as the sum of two abundant numbers up to LIMIT (28123).

 * Variables:
   LIMIT: Constant set to 28123 (all numbers above this can be expressed as sum of two abundants)
   is_abundant: Boolean array marking abundant numbers
   abundant_numbers: Array storing all abundant numbers found
   abundant_count: Count of abundant numbers found
   is_sum_of_abundants: Boolean array marking numbers that are sums of two abundants
   total: Final sum of numbers not expressible as sum of two abundants
 
 * Functions:
   sum_proper_divisors(n): Calculates sum of proper divisors of n
 
 * Output: Sum is: 4178971
 * Time Taken: Approx 4.2 sec
 * Time Complexity : 


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 28123

// function to calculate sum of proper divisors of n
int sum_proper_divisors(int n) {
    if (n == 1) return 0;
    
    int sum = 1;  // 1 is a proper divisor for all n>1
    int sqrt_n = sqrt(n);
    
    for (int i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            sum += i;
            int complement = n / i;
            if (complement != i) {
                sum += complement;
            }
        }
    }
    return sum;
}

int main() {
    // Identify all abundant numbers up to LIMIT
    bool is_abundant[LIMIT + 1] = {false};
    int *abundant_numbers = malloc((LIMIT + 1) * sizeof(int));
    int abundant_count = 0;

    for (int i = 1; i <= LIMIT; i++) {
        if (sum_proper_divisors(i) > i) {
            is_abundant[i] = true;
            abundant_numbers[abundant_count++] = i;
        }
    }

    // Marking all numbers that can be written as sum of two abundant numbers
    bool is_sum_of_abundants[LIMIT + 1] = {false};
    
    for (int i = 0; i < abundant_count; i++) {
        for (int j = i; j < abundant_count; j++) {
            int sum = abundant_numbers[i] + abundant_numbers[j];
            if (sum > LIMIT) break;
            is_sum_of_abundants[sum] = true;
        }
    }

    // Calculate the sum of numbers that cannot be written as such sums
    long long total = 0;
    for (int i = 1; i <= LIMIT; i++) {
        if (!is_sum_of_abundants[i]) {
            total += i;
        }
    }   

    printf("Sum is: %lld\n", total);
    
    free(abundant_numbers);
    return 0;
}