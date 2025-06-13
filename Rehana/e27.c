/*Program to find the product of the coefficients (a, b) for the quadratic expression:n^2 + a*n + b that
 produces the max no of consecutive prime nos for consecutive values of n starting from n = 0.
 tc: abn
 output 71,-59231
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Check if number is prime
int is_prime(int num) {
    if (num<2) return 0;
    for (int i=2;i*i<=num;i++) {
        if (num%i==0) 
        return 0;
    }
    return 1;
}

int main() {
    int max_cnt=0;
    int prod=0;

    for (int a=-999;a<1000;a++) {
        for (int b=-1000;b<=1000;b++) {
            int n=0;
            while(1){
                int val=n*n+a*n+b;
                if(!is_prime(val))
                    break;
                n++;
            }

            if(n>max_cnt){
                max_cnt=n;
                prod=a*b;
            }
        }
    }

    printf("max consecutive primes %d ",max_cnt);
    printf("product %d ",prod);

}
