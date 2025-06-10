/*Finds the sum of all numbers that are equal to the sum of the fifth powers of their digits.
 i extracted the digits,computed 5th power of each digit,added these powers together,if the resulting sum 
 = original no, it is taken 
 o/p found 4150
found 4151
found 54748
found 92727
found 93084
found 194979
tc:O(nlogn)
sum 443839
 ***/
#include <stdio.h>
#include <math.h> 

int main(){
    int sum=0;

    for (int i=10;i<=200000;i++) {
        int x=i;
        int digitS=0;

       
        while(x>0) {
            int digit=x% 10;
            digitS+=(int)pow(digit,5); 
            x/=10;
        }

        if (digitS==i){
            printf("found %d\n",i);
            sum+=i;
        }
    }

    printf("sum %d ",sum);
   
}
