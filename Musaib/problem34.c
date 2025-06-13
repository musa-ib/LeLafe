/* 145 is a curious number, as 1!+4!+5! = 1+24+120 = 145.
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: As 1!=1 and 2!=1 are not sums they are not included.
Answer = 40730
Time Complexity =O(nlogn)
*/

#include<stdio.h>

int fact[10]={1};// stores factorial of numbers from 0 to 9,0!=1

// calculate sum of fcatorial of digits of a number n
int sum_fact_dig(int n){
    int sum =0;
    while(n){
        sum = sum+fact[n%10];
        n=n/10;
    }
    return sum;
}

int main(){
    int p = 1;//stores factorial of i
    for(int i=1;i<=9;i++){
        p = p*i;
        fact[i] = p;//fact[i] = i!

    }
    int sum = 0;
    for(int i=3;i<=2000000000;i++){// calculate sum of curious numbers till 2B
        if(i==sum_fact_dig(i)){
            sum +=i;
        }
    }

    printf("%d",sum);


}