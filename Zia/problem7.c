#include <stdio.h>

int main() {
    int num = 2;
    int count = 0;
    int i;
    int isprime;

    while (count < 10001) {  
        isprime = 1;

        for (i = 2; i < num; i++) { 
            if (num % i == 0) {
                isprime = 0;
                break;
            }
        }

        if (isprime == 1) {
            count++;
            if (count == 10001) {
                printf("%d\n", num);
            }
        }

        num++;
    }

    return 0;
}
