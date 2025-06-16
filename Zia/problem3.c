
//program to check highest
#include <stdio.h>
#include <math.h>

int main() {
    long long number = 600851475143;
    long long factor=2;
    while(factor * factor <= number)// loop will cntinue unitl factor ^2 until we have tried all factors upto sqrt of number
    {
    if(number % factor ==0)// if factor divides evenly remove the number
    {
    number /= factor;
    }
    else{
        factor++;
    }
}
printf("largest prime is %d",number);
return 0;

    // for ( long long i= 1; i <= number; i++) {
    //     if (number % i == 0) {
    //         int isPrime = 1;

    //         if (i <= 1) {
    //             isPrime = 0;
    //         } else {
    //             for (int j = 2; j < sqrt(i); j++) {
    //                 if (i % j == 0) {
    //                     isPrime = 0;
    //                     break;
    //                 }
                
    //             }
    //             isPrime = 1;
    //         }

    //         // printf("%d", i); 
    //      if(isPrime){
    //         if(i>largestPrimeDivisor){
    //             largestPrimeDivisor=i;

    //         }
    //      }
    //             printf(" largest prime divisor   is %d\n", largestPrimeDivisor);

    //     }}


    return 0;
}
