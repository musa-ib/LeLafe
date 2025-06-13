#include<stdio.h>
#include<stdbool.h>

bool is_palindrome(int n){
    int a = n;
    int r;
    int p=0;
    while(n>0){
        r = n%10;
        p = p*10 +r;
        n = n/10;
    }
    if(a==p){return true;}
    else return false;
}

int max(int a, int b){
    if(a>b)return a;
    else return b;
}
int main(){
    int m = 0,n,a,b;
    for(int i=999;i>99;i--){
        for(int j=i;j>99;j--){
            int p = i*j;
            if(is_palindrome(p)){
                n = m;
                m = max(m,p);
                if(n!=m){
                    a=i;b=j;
                    break;
                }
            }
        }   
    }

    printf("%d\t%d\t%d",m,a,b);
}