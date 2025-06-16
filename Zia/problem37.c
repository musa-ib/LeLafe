// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

// NOTE: 
// 2, 
// 3, 
// 5, and 7
//  are not considered to be truncatable primes.

//output=8920
//time taken=1.723 seconds 
//i made a function that is checking prime numbers
//send the prime number to other function that is checking whether the number is truncable prime or not truncable prime is the prime number when moving from right to left cuttind didgit one by one the
//number remained is itself prime and vice versa in checking the number from right to left i found the quotient of the number and checking its
//prime or not if found move forward and divide the quotient again with 10 again checking whether number is prime until we get quotient =0 and vice vers
#include <stdio.h>

int primeNumbers(int number){
    if (number < 2) return 0;

    for(int i=2; i*i<=number; i++){
        if(number%i==0){
            return 0;
        }
    }
    return number;
}

int truncatablePrimes(int number) {
    if (number == 0) return 0;

    //  Right to Left truncation
    int temp = number;
    while (temp > 0) {
        int result = primeNumbers(temp);
        if (result != temp) return 0;  
        temp /= 10;
    }

    //  Left to Right truncation
    int divisor = 1, temp2 = number;
    while (temp2 >= 10) {
        temp2 /= 10;
        divisor *= 10;
    }

    temp2 = number;
    while (divisor > 1) {
        temp2 = temp2 % divisor;  
        int result = primeNumbers(temp2);
        if (result != temp2) return 0; 
        divisor /= 10;
    }

    return 1; 

}
int main() {
    int count = 0;
    int sum = 0;

    for(int i = 11; i < 99999; i++) {
        int primes = primeNumbers(i);

        int truncatablePrimess = truncatablePrimes(primes);

        if (truncatablePrimess) {
            printf("Truncatable Prime Found: %d\n", primes);
            count++;
            sum += primes;

            if (count == 11) break;  
    }
    }
    printf("\nTotal Sum of 11 Truncatable Primes = %d\n", sum);
}
