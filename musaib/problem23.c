/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1+2+4+7+14=28 , which means that is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1+2+3+4+6=16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

Time Complexity = O(n^2)
Answe = 4179871
*/


#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Function tht calculates sum divisors from 1 to n-1;
int DivSum(int n){
    if(n==1)return 0;
    int div_sum=1;// stores sum of divsors, initialized with one because one is proper divsor of every number
    int sq = ceil(sqrt(n));//calculates square root, where we will stop the loop
    if(sq*sq==n)div_sum+=sq;// if number is perfect square we add its square root as divsor
    for(int i=2;i<sq;i++){  // loop frrom 2 to square root -1
        if(n%i==0){
            div_sum = div_sum + i + (n/i); //if a number is divided by number i then i, quotient both are divsors of n
        }
    }
    return div_sum;
}

int main(){
    bool arr[28124]={0}; //flag for abundant number
   
    for(int i=1;i<=28123;i++){ 
        if(i<DivSum(i)){    //checks if number i is abundant and marks arr[i] as 1
            arr[i]=1;
        }
    }
    bool abundant_sum[28124]={0}; // flag for numbers which can be expressed as sum of two abundant numbers

    int sum = 0; // stores sum of numbers which can't be expressed as sum of 2 abundant numbers

    for(int i=1;i<28124;i++){
        if(arr[i]){
            for(int j=i;j<28124;j++){
                if( arr[j]==1 && (i+j)<28124){
                    abundant_sum[i+j] = 1;  // marks the number 1 which is sum of 2abundant numbers
                }
            }
        }
    }
     
    // calculate sum of positive integers which cannot be written as the sum of two abundant numbers.
    for(int i=0;i<=23123;i++){
        if(!abundant_sum[i]){
            sum += i;
        }
    }
    printf("%d",sum);
}