/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, 
and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 
3797, 379, 37, and 7.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

Answer = 748317
*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

//Function to check whether a number n is prime or not
bool isPrime(int n){
    if(n<2)return false;// if number is negative or 0 or 1 return not prime
    if(n==2)return true;// 2 is prime number
    if(n%2==0)return false;// all even numbers except 2 are not prime
    int sq = sqrt(n);
    for(int i=3;i<=sq;i=i+2){
        if(n%i==0){        // check all other numbers by dividing them from 3 to square root
            return false;
        }
    }
    return true;
}


// reverse a number n
int revNum(int n ){
    int rev = 0;
    while(n){
        rev = rev*10 + n%10;
        n = n/10;
    }
    return rev;
}

//Removes didgits from right to left and checks whether remaining number is prime or not
bool isPrimeRemDigitsR(int n){
    while(n){
        if(!isPrime(n)){
            return false;
        }
        n=n/10;// removes right most digit
    }
    return true;
}

//Removes didgits from left to right and checks whether remaining number is prime or not
bool isPrimeRemDigitsL(int n){
    while(n){
        if(!isPrime(n))return  false;
        n = revNum(n);//reverse number   e.g n =3971, reverse = 1793
        n = n/10;      // remove right most digit   179
        n = revNum(n); // reverse remaining number  971
    }

    return true;
}

int main(){
    int sum = 0; // holds sum of truncable primes
    int count=0; // counts number of truncable primes
    int i = 11; // start with number 11 as 2 3 5 7 are not allowed
    while(count<11){ //the loop breaks when we find all truncable primes which are 11
        if(isPrimeRemDigitsR(i) && isPrimeRemDigitsL(i)){
            sum += i;
            printf("%d\t",i);
            count++; // increment counter when a truncable prime is found
        }
        i = i+2; // increment i by two because even numbers are not prime
    }
    printf("\n%d",sum);
}