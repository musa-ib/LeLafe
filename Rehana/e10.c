#include <stdio.h>
#include <stdbool.h>

bool P(long long n) {
    int cnt = 0 ;
    for (int i = 1; i *i <= n; i++) {
        if (n% i== 0) {
            cnt++;
            if(n/i!=i ){
                cnt++ ;
            }
        }
    }
    if (cnt == 2 ) {
        return true;
    } 
        else {



        return false;
    }
}

int main() {
    long long sum =0;

    for (long long i =2; i <2000000 ; i++ ) {
        if (P(i)) {
            sum += i;
        }
    }

        printf("Sum %lld ", sum);
   
}
