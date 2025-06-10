/*
Find the value of d<=1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
Answer = 983
Time Complexity = O(d*l)
l = length of recurring cycle
*/

#include<stdio.h>

//Function to calculate recurring cycle
int recurring(int n){
    int arr[1000] = {0};//stores positon of remainder  a[i] = x means i is at position in x in division
    int rem = 1%n;//stores remainder
    int rec_pos=0; // stores postion of remainder

    while ((rem!=0)){// break the loop when  no. cannot be further divided
        if (arr[rem]!=0)return rec_pos-arr[rem];//if remainder repeats then recurring cycle exists and its length is current postion-prev position
        arr[rem] = rec_pos++;// assign array[remainder] with its posiiton in division
        rem = (rem*10)%n; // calculate next remainder
    }
    return 0;//return 0 if there is no cycle
    
}

int main(){
    int r = 0;//Stores longest length of recurring cycle
    int num;// number which produces longest cycle
    // printf("%d\t",recurring(4));
    for(int i=2;i<=1000;i++){
        int rec = recurring(i);
        // printf("%d\t",rec);
        if (rec>r){
            r = rec;
            num =i;
        }

    }
    printf("%d",num);
}
