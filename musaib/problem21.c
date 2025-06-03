/*
Evaluate the sum of all the amicable numbers under 10000
time complexity = O(n)
space complexity = O(n)
.*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

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
    bool arr[10000]={0};// array that will act as flag, if a number i is amicable then arr[i] =1
    int sum = 0; //stores sum of amicable numbers
    int a,b; //these will store amicable pais 
    for(int i=2;i<=10000;i++){

        if(arr[i]==0){
            a = DivSum(i);
            b = DivSum(a);
        
            if(a<10000 && b<10000 && i==b && a!=b){
                arr[a]=1;
                arr[b] = 1;
            }
        }
    }

    // calculate sum of amicable numbers if arr[i]=1 then number is amicable and add it to sum
    for(int i=0;i<10000;i++){
        if(arr[i]==1){
            sum += i;
        }
    }
    printf("%d",sum);
}