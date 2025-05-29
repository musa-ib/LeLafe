#include<stdio.h>
#include<math.h>
int main(){
    int n=1,m=2;
    int a=0,b=0,c=0;
    int num = 1000;
    int sq = sqrt(num);
    for(n=1;n<sq;n+=2){
        for(m=2;m<sq;m+=2){
            if(m>n){
                a = m*m - n*n;
                b = 2*m*n;
                c = m*m + n*n;
            }
            if(a+b+c==1000){break;}
        }
    }
    printf("%d\t%d\t%d\t%d",a,b,c,a*b*c);
}