#include<stdio.h>
int main(){
    int N = 4000000;
    int a = 1, b = 2;
    int s = 0,c=0;
    while(c<N){
        c=a+b;
        a=b;
        b=c;
        if(c%2==0){
            s=s+c;
        }
    }
    printf("%d",s);
}