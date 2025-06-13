/*Program to find the sum of nos on diagonals in a spiral square sqaure where the spiral starts with 1 at the center
and moves in clockwise dir.for odd spiral i used this to calculate Sum of corners: 4*n^2-6*(n-1) by examining top-right corner 
topleft corner,bottom-left corner,bottom-right corner
i started from center =1 and similarly for others. For each spiral layer I found total sum of the diagonals
tc:o(n)
Sum of diagonals 669171001
*/
#include <stdio.h>
int main(){
    int size=1001;
    long long sum=1;  //start from center value

    for(int n=3;n<=size;n+=2) {
        sum+=4*n*n-6*(n-1);
    }

    printf("sum of diagonals %lld ",sum);
    
}     
