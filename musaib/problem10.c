#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool is_prime(int n){
    int sq = sqrt(n);
    for(int i=2;i<=sq;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    long long n = 2000000,s=2;
    for(int i=3;i<n;i++){
        if(i%2==0)continue;
        if(is_prime(i)){
            s = s+i;
        }
    }
    printf("%lld",s);
}