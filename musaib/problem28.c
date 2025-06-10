/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 101 by 101 spiral formed in the same way?
Answer = 669171001

Time complexity = O(n^2)
*/

#include<stdio.h>
#include<stdlib.h>
#define N 1001 // Size of spiral MAtrix

int main(){
    int n = N*N; // LAst number in matrix
    int * arr[N];
    for(int i=0;i<N;i++){
        arr[i] = (int *)malloc(sizeof(int)*N);// Dynamic allocation of N*N array
    }
    
    int srow = 0,scol=0,erow=N-1,ecol=N-1;// Starting row,column =0, ending rwo,column =N-1
    while(srow<=erow||scol<=ecol){
        for(int j =ecol;j>=scol;j--){ //start from the top right towards left which is last number
            arr[srow][j] = n;
            n--;
        }
        for(int i=srow+1;i<=erow;i++){ //then move down
            arr[i][scol]=n;
            n--;
        }
        for(int j=scol+1;j<=ecol;j++){// then right
            arr[erow][j]=n;
            n--;
        }
        for(int i=erow-1;i>=srow+1;i--){ // the back to top and stop before top right
            arr[i][ecol]=n;
            n--;
        }
        srow++;erow--;
        scol++;ecol--;

    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         printf("%d\t",arr[i][j]);
    //     }
    //     printf("\n");
    // }
    int sum=0;
    for(int i=0;i<N;i++){// calculate sum of diagaonal elements
        sum += arr[i][i];
        sum+=arr[i][N-1-i];
    }
    printf("%d",sum-1);// subtract sum by 1 as center element(1) is counted twice
}
