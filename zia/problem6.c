
#include <stdio.h>

int main() {
   
    int i;
     int j=0;
     int k=0;
     int l;
     int difference;
    for(i = 1; i <= 100; i++) {
        j+=i*i;
        k += i;
     
    }
   printf("summm of square = %d\n", j);

   
   
     printf("sum from 1 to 100 = %d\n", k);
    l=k*k;
    printf("squae of sum = %d\n", l);
  difference=l-j;
  printf("difference = %d\n", difference);
}  
