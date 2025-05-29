#include <stdio.h>

int main() {
    int n = 2000000;
    int i, j;
   int sum = 0;  
 int isprime = 1;
    for (i = 2; i <= n; i++) {
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                 isprime = 0;
                break;  
            }
        }
           if (isprime) {
        sum += j;
    }
    }

    printf("sum is %lld\n", sum);

    return 0;
}
