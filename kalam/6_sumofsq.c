#include <stdio.h>

int main() {
     int n = 100;
    long sum = 0;             
     long sum_of_squares = 0;  
     long square_of_sum; 
    long difference;          

    
    for (int i = 1; i <= n; i++) {
         sum += i;
        sum_of_squares += i * i; 
    }

           square_of_sum = sum * sum;           
     difference = square_of_sum - sum_of_squares;  

    printf("The diff is: %ld\n", difference);

    return 0;
}
