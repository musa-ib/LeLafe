/*
Q. Find the sum of all multiples of 3 or 5 below 1000.
  
   
   

    Time Complexity- O(N)
    Time Taken- 0.4 sec
    Output= 233168
*/




#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("%d\n", sum); 
    return 0;
}