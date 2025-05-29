#include <stdio.h>
#include <stdbool.h>


bool Prime(int n){
    int cnt = 0 ;
    for (int i = 1; i* i <=n; i++) {
        if (n%i==0 ) {
            cnt++;
            if(n/i!=i ){
                cnt++ ;
            }
        }     
    }
    if(cnt==2 ){
        return true;
    } else {


        return false;
    }
    
}

int main(){
    int count =0;
    int i =1;

    while(count <10001) {
        i++ ;
        if (Prime(i) ) {
            count++ ;


           }
    }




            printf("10001st prime number is %d ", i );
    
}
