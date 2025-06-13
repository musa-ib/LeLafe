#include <stdio.h>

#define N 400  

int main(){
    int res[N];

    
    for (int i=0;i<N;i++) {
        res[i]=0;
    }

    res[0]=1; 
    int len=1;

    for (int i=1; i<=1000;i++) {
        int c=0;
        for (int j=0;j<len;j++) {
            int var=res[j]*2+c;
            res[j]=var%10;
            c=var/10;
        }
        while (c>0) {
            res[len]=c%10;
            c/=10;
            len++;
        }
    }

    int sum=0;
    for (int i=0;i<len;i++) {
        sum+=res[i];
    }

    printf("sum of digits %d ",sum);
   
}  