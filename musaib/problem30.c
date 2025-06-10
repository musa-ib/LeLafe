/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
            1634 = 1^4 + 6^4 + 3^4 + 4^4
            8208 = 8^4 + 2^4 + 0^4 + 8^4
            9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1^4=1 is not a sum it is not included.

The sum of these numbers is 
1634+8208+9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

Answer = 443839

Time COmpleity = O(nlogn)
*/

#include<stdio.h>
#include<math.h>
int power[10];// stores 5th power of numbers 0 to 9

// calculate summation of 5th power of digits of number n
int pow_digit(int n){
    int sum = 0;
    while(n){
        sum += power[n%10];
        n = n/10;
    }
    return sum;

}
int main(){
    for(int i=0;i<=9;i++){
        int p = pow(i,5);
        power[i]= p;
    }
    int sum = 0;
    for(int i=2;i<2147483647;i++){// range of int in c =2147483647
        if(i==pow_digit(i)){
            sum = sum + i;
            // printf("%d\t",i);
        }
    }

    printf("%d",sum);
}