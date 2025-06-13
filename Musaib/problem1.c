#include<stdio.h>
int main(){
    int n  = 1000;
    int s = 0;
    for(int i=3;i<n;i++){
        if(i%3==0 || i%5==0){
            s = s+i;
        }
    }
    printf("%d",s);
    return 0;
}