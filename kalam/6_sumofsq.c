/**
 Q. Sum Square Difference
 *
  This program computes the difference between:
  1. The square of the sum of the first N natural numbers
  2. The sum of the squares of the first N natural numbers

 * Variables:
   int n                       : Upper bound of natural numbers to consider
  long long sum               : Sum of first n natural numbers
  long long square_of_sum     : Square of the sum
  long long sum_of_squares    : Sum of the squares
  long long difference        : Final result (square_of_sum - sum_of_squares)
 
 * Functions:
  int main()     Calculates and prints the result.
 
 * Output: 25164150
 
 * Time taken: Instantaneous (O(1))
 */

#include <stdio.h>

int main() {
    // Define the upper limit
    int n = 100;

    // Calculate the sum of the first n natural numbers
    long long sum = n * (n + 1) / 2;

    // Calculate the square of the sum
    long long square_of_sum = sum * sum;

    // Calculate the sum of the squares of the first n natural numbers
    long long sum_of_squares = n * (n + 1) * (2 * n + 1) / 6;

    // Compute the difference
    long long difference = square_of_sum - sum_of_squares;

    // Print the result
    printf("Difference is: %lld\n", difference);

    return 0;
}
