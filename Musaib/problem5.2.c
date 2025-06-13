#include<stdio.h>

int lcm(int a, int b){
    int i = 1;
    int c=a;
    while(c%b!=0){
        i++;
        c = a*i;
        
    }
    return c;
}
int main(){
    int l = 1;
    for(int i=1;i<=20;i++){
        l = lcm(l,i);
    }
    printf("%d",l);
}