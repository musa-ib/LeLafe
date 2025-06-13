/*
    What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
    Answer = 2783915460
    Time complexity = O(n^2)

*/

#include<stdio.h>

// Function for calculaion of factorial of number n
int fact(int n){
    if(n==0)return 1;
    int p = 1;
    for(int i=1;i<=n;i++){
        p = p*i;
    }
    return p ;
}

// Swap two numbers in an array
void swap(int nums[], int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int main(){
    int term = 0; //How much terms we have covered
    int nums[10] = {0,1,2,3,4,5,6,7,8,9};// Input numbers
    int i=0,j=0; // j finds the next numberand swaaps with i for correct position
    int indx = 1000000;//index of term which we have to find
/*
    starting with let 0 be fixed at first place then we can generate(n-1)! numbers
    if(n-1)! < index that means 0 isn't at correct postion, place 1 and first place and so on
    if(n-1)>=index that means the number pointed by i is at correct postion and increment it to find next number
*/
    while(i<10){
        if(term==indx)break;// get out of loop if number is found
        int f = fact(10-i-1);
        if(f+term<indx){
            if(j>=9)j=i;
            swap(nums,i,j+1);// swap number at ith index with number at j+1th index
            j++;
            term+=f;
        }
        else {i++;j=i;}//if digit at correct index then move tp next index
        if(i==9)term++;//when i reaches the the last index , all numbers are at correct position, we don'y need further swaping
        // so increment term and get out of loop
    }
    for(int i=0;i<10;i++){
        printf("%d",nums[i]);
    }
    // printf("%d",fact(4));
}