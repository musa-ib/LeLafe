/*
Find the sum of the digits in the number 100!
time complexity = O(m*n)
m = size of array, n = Number
*/

#include<stdio.h>
int main(){
    int n=100; // 
     int arr[1000]={0};// to store 100!
     arr[999] =1;// intilaize last element with 1 reprsenting 1! 

     // calulate 100!
    for(int i =2;i<=100;i++){
        int carry = 0;
        for(int j=999;j>=0;j--){
            int p = arr[j]*i + carry;// Multiply whole rray by i and add carry of previous multiply 
            
            carry = p/10; // if product is >9, generate carry by dividing it by 10
            arr[j] = p%10;// store ones place digit at array[j]
            
        }
    }

    int sum = 0;// sotres sum of digits of 100!

    // calculating sum of digits of 100!
    for(int j=0;j<1000;j++){
        sum+=arr[j];
    }
    printf("%d",sum);
}