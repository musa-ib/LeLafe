/* 
Q.What is the index of the first term in the Fibonacci sequence to contain 1000 digits?


Approach:
We compute each Fibonacci number step-by-step.
    -Also count its digits until we find the first one with 1000 digits.
Start with the first two Fibonacci numbers:
    -Compute the next Fibonacci number
Count the digits of Fib_Current
    -Repeat until we find the answer

Time Taken: 2.9 secs
Time Complexity- 0(d*n)- n is the no of digis

*/



#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

// Function to add two numbers represented as arrays
void addNumbers(int a[], int b[], int result[]) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

// Function to count the number of digits in a number represented as an array
int countDigits(int num[]) {
    int count = MAX_DIGITS;
    while (count > 0 && num[count - 1] == 0) {
        count--;
    }
    return count == 0 ? 1 : count;
}

int main() {
    int fib1[MAX_DIGITS] = {0}; // F(n-1)
    int fib2[MAX_DIGITS] = {0}; // F(n-2)
    int fibCurrent[MAX_DIGITS] = {0}; // F(n)

    // Initialize F(1) = 1
    fib1[0] = 1;
    // Initialize F(2) = 1
    fib2[0] = 1;

    int index = 2; // Start from F(2)

    while (1) {
        // Compute F(n) = F(n-1) + F(n-2)
        addNumbers(fib1, fib2, fibCurrent);

        index++;

        // Check if F(n) has at least 1000 digits
        if (countDigits(fibCurrent) >= 1000) {
            printf("the indexs %d.\n", index);
            break;
        }

        // Update F(n-2) and F(n-1) for the next iteration
        memcpy(fib2, fib1, sizeof(fib1));
        memcpy(fib1, fibCurrent, sizeof(fibCurrent));
    }

    return 0;
}