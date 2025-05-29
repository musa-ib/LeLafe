#include<stdio.h>
#include<math.h>

int count_div(int n){
    if(n==1)return 1;
    int cnt = 2;
    int sq =sqrt(n);
    if(sq*sq==n){cnt++;}
        for(int i = 2;i<sq;i++){
            if(n%i==0){
                cnt=cnt+2;
            }
        }
    
    return cnt;
}
int main(){
    int c = 0;
    int s = 0, i=1;
    while(c<500){
        s=s+i;
        i++;
        c= count_div(s);
    }
    printf("%d\t%d",s,i);
}