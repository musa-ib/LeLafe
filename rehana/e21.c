#include <stdio.h>
/*
This program finds the sum of all amicable numbers under 10000
sumtotal: holds final sum of all amicable nos
a,b:vars to hold a no. and its corresponding sum of divisors
sumDiv(n):function that returns the sum of proper divisors of n (excluding n itself)
For each number a from 2 to 9999:
Calculate the sum of its proper divisors and store it in `b`if a≠b and sumDiv(b)==a, then a and b form an amicable pair
Add `a' to the total (we don’t add both to avoid repeats we’ll reach `b` )

In sumDiv 
start sum as 1 since 1 is always a proper divisor
for all i from 2 to √n, if i divides n
add i and its pair n/i to the sum (if they are different)
o/p
sum of all amicable nos 31626

time taken O(n√n)  where n = 10000 since we check each number and find its divisors up to √n
*/


//find sum of proper divisors of n
int sumDiv(int n) {
    int sum = 1;
for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i; }
            }
        }
    return sum;
}


int main() {
    int sumtotal=0; //total sum of amicable nos

    for (int i=2;i<10000;i++){
        int a=i;
        int b=sumDiv(a); //find sum of divisors of a
    // check if a and b are amicable
        if(a!=b && sumDiv(b)==a){
            sumtotal+=a; //add to total if they form an amicable pair
        }
    }

    printf("sum of all amicable nos %d", sumtotal);
 
}
