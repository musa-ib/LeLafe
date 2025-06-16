// Find the product of the coefficients, a
//  and b
// , for the quadratic expression that produces the maximum number of primes for consecutive values of 
// , starting with n=0;
//output 59231
//time taken=0.724 seconds
//i was supposed to find the vslues of a and b which will produce the maximum primes starting from n=0; quadratic equation is
// n * n + a * n + b; what i did is i looped through a nd b and made a function primechecer to return true or false.on calcualting the uadraticc equations value evrytime
// i m using function call in order to check if its prime or not if the number is  prime the n gets increment keeping the values of a and b same;
// once each time thevalue of n is stored in maxPrime.onnce function returns false that is its not prime the while llop breaks increementing ths b now and so on.
// everytime the alue of maxprime is changed depending on n; after iterating whole if tracks the value of a and b at max n value
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
     int maxPrimes = 0;
    int bestA = 0, bestB = 0;
    for (int a = -999; a <= 999; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n = 0;
            while (1) {
                int val = n * n + a * n + b;
                if (!isPrime(val)) break;
                n++;
            }
               if (n > maxPrimes) {
                maxPrimes = n;
                bestA = a;
                bestB = b;
            }
        }
    } printf("Product of coefficients: %d\n", bestA * bestB);

    return 0;
}
