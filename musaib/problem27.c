/*Find the product of the coefficients, a and b, for the quadratic expression n^2+a*n+b 
that produces the maximum number of primes for consecutive values of n, starting with n=0.
|a|<1000 and |b|<=1000

Answer = -59231*/


#include<stdio.h>
#include<stdbool.h>
#include<math.h>

//Function to check whether a number n is prime or not
bool isPrime(int n){
    if(n<2)return false;// if number is negative or 0 or 1 return not prime
    if(n==2)return true;// 2 is prime number
    if(n%2==0)return false;// all even numbers except 2 are not prime
    int sq = sqrt(n);
    for(int i=3;i<=sq;i++){
        if(n%i==0){         // check all other numbers by dividing them from 3 to square root
            return false;
        }
    }
    return true;


}

int main(){
    int A,B; // stores coefficients a and b for quadratic exp which produce max no of consecutive primes
    int max_primes = 0;// stores max no of consecutive primes
    
    for(int a =-999;a<1000;a++){// start a from -999 to 999
        for(int b=-1000;b<=1000;b++){// b from -1000 to 1000
            int cnt_primes = 0;// number of consecutive primes for current a and b
            int n=0;
            while(n<2147483647){
                if(isPrime((n*n)+(a*n)+b)){
                    cnt_primes++;
                    n++;
                }
                else break;
            }
            if(cnt_primes>max_primes){
                max_primes = cnt_primes;
                A=a; B=b;
            }
        }
    }
    printf("%d",A*B);
}