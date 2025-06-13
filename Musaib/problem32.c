/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; 
for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39*186=7254, containing multiplicand, multiplier, and product is 1 through 
9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

Answer = 45228

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// compare function for qsort
int compare_chars(const void *a, const void *b) {
  return (*(char *)a - *(char *)b);
}

// Search target elementin array
//if present return false else true
bool linearSearch(int arr[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return false; 
    }
  }
  return true;
}


int main(){
    int arr[100000]={0};// store products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
    int inx=0;//index to the array
    char num[]="123456789";// to compare with multiplicand/multiplier/product string
    int sum = 0; // stores sum of pandigit products
    for(int i=1;i<1000;i++){
        for(int j=i;j<10000;j++){
            int p = i*j;
                
            char m1[5],m2[5],pd[10];//stores string of multiplicand,multiplier and product repectively
            sprintf(m1,"%d",i);//convert integer to string
            sprintf(m2,"%d",j);
            sprintf(pd,"%d",p);
            if(strlen(m1)+strlen(m2)+strlen(pd)==9){// check if length of strings of multiplicand,multiplier and product is 9
                                                    //if it less or greater than 9 then doesn't 1 to 9 digits exactlyonce
                strcat(pd,m1);  // concatnate the multiplicand,multiplier and product strings
                strcat(pd,m2);
                qsort(pd, strlen(pd), sizeof(char), compare_chars);// sort the concatenated string
            }
            if(strcmp(pd,num)==0){//compare with num string if equal add to sum 
                if(linearSearch(arr, 100000, p)){ // search element in array
                    arr[inx++]=p;
                    sum+=p;
                }
            }

        }
    }
    printf("%d",sum);
}