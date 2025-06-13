#include<stdio.h>


int seq_len [1000000] = {0};

int count_seq(long long n){
    int c = 1;
    long long  n1 = n; 
    while(n>1){
        if(n<n1 && seq_len[n]!=0){
            return c+seq_len[n]-1;
        }
        else if(n%2==0){
            n = n/2;
            c++;
        }
        else{
            n = 3*n+1;
            c++;
        }
    }
    return c;
}
int main(){
    int number,n = 1000000;
    // int n = 10;
    int cc = 0;
    int c;
    for(int i=1;i<=n;i++){
        c = count_seq(i);
        seq_len[i] = c;
        if(c>cc){
            cc=c;
            number = i;  
        }
    }
    printf("%d\t%d",cc,number);
}