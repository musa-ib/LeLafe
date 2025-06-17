/*
Q. Find the sum of all numbers that can be written as the sum of fifth powers of their digits.

   Approach-using dp
   BAsically we need to find all numbers that are equal to the sum of their digits each raised to the fifth power.
   

    Time Complexity- O(N*D)
    Time Taken- 8 sec
    Output= 443839
*/



#include <stdio.h>
#include <math.h>

int main() {
    int total_sum = 0;
    int upper_limit = 354294; // 6 * 9^5// we needed to set an upper bound
//check from 2 o upperbound then computer the sum of its digits. and also check if the  nu mber equals itself
    for (int num = 2; num <= upper_limit; num++) {
        int temp = num;
        int sum_of_powers = 0;

        while (temp > 0) {
            int digit = temp % 10;
            sum_of_powers += pow(digit, 5);
            temp /= 10;
        }

        if (sum_of_powers == num) {
            total_sum += num;// sum valid numbers
        }
    }

    printf("%d\n", total_sum);
    return 0;
}