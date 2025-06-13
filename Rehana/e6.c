#include<stdio.h>
int main()
{
    int n= 100;
    int s1=0;
    int s2=0 ;
/*for(int i=1;i<=n;i++){
        s2=s2+i*i;
        s1=s1+i;
 }*/
    s1=n *(n + 1) /2;        
    s2=n * (n + 1)*(2 *n + 1)/  6;
    s1=s1*s1;
    int sub= s1-s2;
    printf("sum1 %d ",s1);

printf(" sum2 %d ",s2);
    printf(" sub %d ",sub );
    
}