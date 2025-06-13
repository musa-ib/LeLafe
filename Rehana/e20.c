/*
this program calculates the sum of digits of 100! .N is maxm size of array to hold digits of the factorial 
ans[N] is array to store each digit of the factorial result.digitsUsed is no. of digits currently used in the ans array

i initialized ans array with 1 since 0! = 1 .then i multiplied the current factorial result by each number from 2 to 100
and added carry wherever i occurred.Then store the last digit of product back keep the carry for the next digit
then i summed up all digits of factorial

Output:
Sum of digits 648

Time Taken:
O(n log n), where n is the number whose factorial is to be found  
*/

#include <stdio.h>

#define N 200  // hold digits of 100!

int main() {
    int ans[N];   // store digits of factorial
    int i,j,c,digitsUsed = 1;
    int sum=0;

    ans[0]=1;  //  start with 1 since 0!=1
    
      
    for(i=1;i<N;i++){
        ans[i]=0;}

    // multiply result by every no. from 2 to 100
    for(i=2;i<=100;i++){
        c=0;

        // multiply current no with each digit
        for(j=0;j<digitsUsed;j++){
            int product=ans[j]*i+c;
            ans[j]=product%10;     //  digit in ans array
            c = product/10;         // carry 
        }

        // add remaining carry as new digits
        while (c>0){
            ans[digitsUsed]=c% 10;
            c=c/10;
            
            digitsUsed++;
        }
    }

    // added all digits of factorial
    for (i=0;i<digitsUsed;i++){
        sum+=ans[i];
    }

    printf("Sum of digits %d ",sum);
    
}
