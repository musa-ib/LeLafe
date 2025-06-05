/* this prog finds the index of the first Fibonacci number that has at least 1000 digits.

 index tracks the current Fibonacci index starting from 2 since f1 and f2 are the first two
add function adds 2nd last and preceding one to get current one  
cnDig func counts no of digts in fib series
output 4782
TC O(N)
*/
 





#include <stdio.h>
#include <string.h>

#define N 1000

//add two numbers  preceding of fib 
void add(int a[], int b[], int res[]) {
    int c = 0;
    for (int i=0; i<N;i++) {
        int sum=a[i]+b[i]+c;
        res[i]=sum%10;
        c=sum/10;
    }
}

// to count digits ,i ignored zeroes which came from msb side
int cntDig(int no[]) {
    for (int i=N-1; i>=0;i--) {
        if (no[i]!=0)
            return i+1;
    }
    
}

int main() {
    int f1[N]={0}; //second last
    int f2[N]={0}; //preceding 
    int f3[N]={0};  //current

    f1[0]=1;  
    f2[0]=1;  

    int index=2;

    while(1){
        add(f1,f2,f3);  // f3=f1+f2
        index++;

        if (cntDig(f3)>=1000)
            break;

        // Shift values for next iteration using loops 
        for (int i=0;i<N;i++) {
            f1[i]=f2[i];
            f2[i]=f3[i];
        }
    }

    printf("index of Ist fib no. with 1000 digits %d ", index);

}
