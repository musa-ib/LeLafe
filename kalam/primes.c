#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 2000000

int main() {

clock_t start, end;
double cpu_time_used;
start = clock(); 
    
    bool sieve[LIMIT + 1];
    for (int i = 0; i <= LIMIT; i++) {
        sieve[i] = true;
    }

    sieve[0] = false;
    sieve[1] = false;

    int sqrt_limit = (int)sqrt(LIMIT);
    for (int i = 2; i <= sqrt_limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                sieve[j] = false;
            }
        }
    }

    unsigned long long sum = 0;
    for (int i = 2; i <= LIMIT; i++) {
        if (sieve[i]) {
            sum += i;
        }
    }

    printf("Sum of all primes up to %d is: %llu\n", LIMIT, sum);
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    
    return 0;
}
