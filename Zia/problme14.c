#include <stdio.h>

long collatz_length(long n) {
    long length = 1;  
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        length++;
    }

    return length;
}

int main() {
    long max_length = 0;
    int number_with_max_length = 1;

    for (int i = 1; i < 1000000; i++) {
        long length = collatz_length(i);
        if (length > max_length) {
            max_length = length;
            number_with_max_length = i;
        }
    }

    printf("The starting number under 1,000,000 with the longest Collatz chain is %d with length %ld.\n", number_with_max_length, max_length);

    return 0;
}
