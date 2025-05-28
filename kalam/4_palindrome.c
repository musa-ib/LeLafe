

/******************************************************************************

                            Online C Compiler.
               (n2) Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

LARGEST PALINDROME*******************************************************************************/

#include <stdio.h>
#include <stdbool>

bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int maxPal = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
              int product = i * j;

             if (product <= maxPal)
                 break; 

        if (isPalindrome(product)) {
                 maxPal = product;
             break; 
         }
        }
}

    printf(" %d\n", maxPal);
    return 0;
}
