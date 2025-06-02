#include <stdio.h>
#include <string.h>
long startNo,ans;
long long no;
int terms;
int saveterms=0;
int main(){
for(startNo=2;startNo<1000000;startNo++){
    terms=1;
    no=startNo;
    while(no>1){
        while(no%2==0){
            no/=2;           
             terms++;
        }
        if(no>1){
            no=(no*3)+1;
            terms++;
        }
    }
    if(terms>saveterms){
        saveterms=terms;
        ans=startNo;

    }}

printf("longest chain %d..starting no. %ld",saveterms,ans);
  

}