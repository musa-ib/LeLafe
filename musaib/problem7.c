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
    int i = 1;
    int p = 2;
    while(i<10001){
        p++;
        if(p%2==0)continue;
        if(is_prime(p)){
            i++;
        }
        
    }
    printf("%d",p);
}