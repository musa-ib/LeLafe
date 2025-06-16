// Find the largest palindrome made from the product of two 
// -digit numbers.
// output=906609;
// time=2.042

#include <stdio.h>
int pallindrome = 0;

// Function multiples two numbers  returns the palindrome product, 1 if it is pallindrome 0 if it is not pallindrome
int mulNumbers(int num1, int num2) {
    int product = num1 * num2;
    int exactProduct = product;
    int reversed = 0;

    while (product > 0) {
        int digit = product % 10;
        reversed = reversed * 10 + digit;
        product /= 10;
    }

    if (exactProduct == reversed) {
        return exactProduct;  
    } else {
        return 0;  
    }
}

int main() {
    for (int i = 100; i <= 999; i++) {
        for (int j = 101; j <= 998; j++) {
            int result = mulNumbers(i, j);  
            if (result > pallindrome) {
                pallindrome = result;  
            }
        }
    }

    printf("Largest palindrome made from product of two 3-digit numbers: %d\n", pallindrome);
    return 0;
}
