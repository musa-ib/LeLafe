//How many circular primes are there below one million?
//output=55
//time taken =2.435 seconds
// send number from 1 to 1 million
//check if they are prime or not
// i made a function where i rotated an number from all the possible situations
// and then made is circular prime function checking where all 
//rotated nmbers are prime or not and added them
//to the count function
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int rotateNumber(int num) {
    int lastDigit = num % 10;
    int rest = num / 10;

    int multiplier = 1;
    int temp = rest;
    while (temp > 0) {
        multiplier *= 10;
        temp /= 10;
    }

    return lastDigit * multiplier + rest;
}

bool isCircularPrime(int num) {
    if (!isPrime(num)) return false;

    // Count number of digits
    int digits = 0, temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    int rotated = num;
    for (int i = 0; i < digits - 1; i++) {
        rotated = rotateNumber(rotated);
        if (!isPrime(rotated)) {
            return false;
        }
    }

    return true;
}


int main() {
    int count = 0;

    for (int i = 2; i < 1000000; i++) {
        if (isCircularPrime(i)) {
            count++;
        }
    }

    printf("Total Circular Primes below 1 million: %d\n", count);
    return 0;
}
