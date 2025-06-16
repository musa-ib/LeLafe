/*
The decimal number, 585 = 1001001001(binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

Answer = 872187
*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
char arr[20]={0};// used to store a binary number


//Converts a number n into string of binary and returns string
char * intToBin(int n){
    
    int i=0;//index of string

    //Repeated divide by 2 and store remainder as character in array 
    while(n>0){
        arr[i++] = n%2+'0';
        n = n/2;
    }
    arr[i]='\0';//Add a nullcharacter indicating conversion is complete
    strrev(arr);
    
    return arr;
}

// Checks whether the string is palindrome or not
bool isPalindrome(char* str){
    int l = strlen(str);
    int i=0,j=l-1;
    while(i<j){
        if(str[i]!=str[j])return false;
        i++;j--;
    }
    return true;
}

int main(){
    int sum = 0 ;
    for(int i=1;i<1000000;i++){
        char str[20];
        if(isPalindrome(itoa(i,str,10)) && isPalindrome(intToBin(i))){
            sum = sum + i;
            printf("%d\t",i);
        }
    }
    printf("\n%d",sum);
}

