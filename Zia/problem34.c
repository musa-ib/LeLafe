//Find the sum of all numbers which are equal to the sum of the factorial of their digits.
//output 40730
//time taken=0.677 seconds
//i found the factorial of all numbers and then passed to the function where it is taking out the digits of factorial and then summing checking is the sum equal to the digits
//if yess return it and summing them up;
#include <stdio.h>

int findFactorial(int number) {
    int result = 1;
    while (number >= 1) {
        result *= number;
        number--;
    }
    return result;
}

int isCuriousAndReturn(int number) {
    int temp = number;
    int sum = 0;

    while (temp > 0) {
        int digit = temp % 10;
        sum += findFactorial(digit);
        temp /= 10;
    }

    if (sum == number && number != 1 && number != 2) {
        printf("Curious number found: %d\n", number);
        return number;
    }

    return 0;
}

int main() {
    int totalSum = 0;

    for (int i = 1; i <= 99999; i++) {
        totalSum += isCuriousAndReturn(i);
    }

    printf("\nTotal sum of all curious numbers: %d\n", totalSum);
    return 0;
}
