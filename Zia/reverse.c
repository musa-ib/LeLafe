#include <stdio.h>

int main() {
    int n = 13;
    int i;
    int isPrime = 1;  // assume prime

    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = 0;  // found divisor
            break;
        }
    }

    if (isPrime)
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);

    return 0;
}
