/*
F1 = 1, F2 = 1
F3 = F2 + f1 = 2
What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

Answer = 4782
Time Complexity = O(n^2);
*/

#include<stdio.h>

int main(){
    int fn[1000]={0};//stores ist number  F(n-2)
    int sn[1000]={0};//2nd number F(n-1)
    int nn[1000]={0};//next number in series f(n-2)+F(n-1)
    fn[999]=1; sn[999]=1; //given first two numbers are 1,1
    int carry = 0;
    int index = 2;//nth term in series, first two are given therefore index=2
    while(nn[0]==0 ){
        // to generate nextterm in fib series add ith element of first array with ith element of sectond array 
        //and store thatin ith index of 3rd array
        //if we get sum>9 when adding two ith element of two arrays add carry to (i-1)th elements
        for(int i=999;i>=0;i--){
            int s = fn[i]+sn[i]+carry;// adding two numbers at position i and carry
            carry = s/10;// stores carry
            nn[i] = s%10;//store one's place digit at ith index
            
        }
        index++;

        for(int i=999;i>=0;i--){
            fn[i] = sn[i];
            sn[i] = nn[i];
        }
    }
    printf("%d",index);
}