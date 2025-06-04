#include <stdio.h>

int main() {
    int a = 0;
    int b = 1;
    int c = 0;
    int sum = 0;
    int count=0;

    while (c < 4000000) {
        c = a + b;
        a = b;
        b = c;

        if (c % 2 == 0) {
            sum += c;
        } count++;

    }
                printf(" Fibonacci numbers under 4 million: %d\n", count);


    printf("Sum of even Fibonacci numbers under 4 million: %d\n", sum);
    return 0;
}
