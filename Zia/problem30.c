//Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
//i first calculated the power from 0 to 9 and
//put them in an array and then i looped from 2 to 354294 since Upper limit is 6 * 9^5 = 354294
//i extracted the digits of th numbers that i looped over and on that digit
//i extracted the element preesent at that posiion in array
//summe those element and checked if the 
//sum is equal to the num if yes i added that to total sum
//to the total sum


//output=443839
//timetaken=3.625

#include <stdio.h>
#include <math.h>

int main() {
    int fifthPowers[10];
    
    // Precompute fifth powers of digits 0–9
    for (int i = 0; i < 10; i++) {
        fifthPowers[i] = (int)pow(i, 5);
    }

    int totalSum = 0;

    // Upper limit is 6 * 9^5 = 354294
    for (int num = 2; num <= 354294; num++) {
        int sum = 0;
        int temp = num;

        // Sum the fifth powers of each digit
        while (temp > 0) {
            int digit = temp % 10;
            sum += fifthPowers[digit];
            temp /= 10;
        }

        // Check if number equals the sum of fifth powers
        if (sum == num) {
            printf("Found number: %d\n", num);
            totalSum += num;
        }
    }

    printf("Sum of all such numbers: %d\n", totalSum);
    return 0;
}
