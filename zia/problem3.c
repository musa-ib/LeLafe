// What is the largest prime factor of the number 
// output-6857
// time taken=0.403 second

#include <stdio.h>

int main() {
    long long number = 600851475143;
    long long i = 2;
    long long largestPrimeDivisor = 0;

    while (number > 1) {
        if (number % i == 0) {
            largestPrimeDivisor = i;
            while (number % i == 0) {
                number /= i;
            }
        }
        i++;
    }

    printf("Largest prime divisor: %lld\n", largestPrimeDivisor);
    return 0;
}
