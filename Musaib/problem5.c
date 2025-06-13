#include<stdio.h>

int gcd(int a, int b){
    while(a!=b){
        if(a>b){a=a-b;}
        else b =b-a;
    }
    return a;
}
int main(){
    long long l = 1;
    for (int i=1;i<=20;i++){
        l = (l*i)/gcd(l,i);
    }
    
    printf("%lld",l);
}