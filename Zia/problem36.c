// Problem 36
// The decimal number, 585=1001001001 base 2
//  (binary), is palindromic in both bases.

// Find the sum of all numbers, less than one million, which are palindromic in base 
// 10 and base 2
// .

// (Please note that the palindromic number, in either base, may not include leading zeros.)
// i made two function one to find binary and other to check ballindrome.m in the main function i called binary function
//to find binary of number and passed that to ispallindrome to check given binary number is pallindrome or not if yes i addded that to the sum variable
//output=1772
//time taken =2.201 seconds

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int number) {
    int reversed = 0, original = number;
    while (number != 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed == original;
}

int generateBinaryNumber(int n) {
    int binary = 0;
    int place = 1;
    while (n > 0) {
        int bit = n % 2;
        binary += bit * place;
        place *= 10;
        n /= 2;
    }
    return binary;
}

int main() {
    int sum = 0;

    for (int i = 1; i < 1000000; i++) {
        if (isPalindrome(i)) {
            int binary = generateBinaryNumber(i);  
            if (isPalindrome(binary)) {
                sum += i;
                // printf("Decimal: %d, Binary: %d\n", i, binary);
            }
        }
    }

    printf("\n✅ Final Sum: %d\n", sum);
    return 0;
}
