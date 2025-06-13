#include<stdio.h>
int main(){
    int n = 1001;
    int tr,tl,bl,br;
    int sum=0;
    while(n>1){
        tr = n*n;
        tl = tr-n+1;
        bl = tl-n+1;
        br = bl-n+1;
        sum = sum + tr + tl+bl+br;
        n = n-2;
    }
    printf("%d",sum+1);
}