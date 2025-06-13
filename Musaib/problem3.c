#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool is_prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int max(int a, int b){
    if(a>b)return a;
    else return b;
}

int main(){
    long long n = 600851475143;
    int m = 0;
    for(int i=2;i<sqrt(n);i++){
        if(is_prime(i) && n%i==0){
            m = max(m,i);
        }
    }
    printf("%d",m);
    printf("%d",is_prime(6857));
}