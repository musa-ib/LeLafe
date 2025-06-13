#include <stdio.h>
#include <stdbool.h>


bool Prime(int n){
  
    for (int i=2; i * i <= n; i++) {
        if (n% i==0)
            return false;
    }
    return true;
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
