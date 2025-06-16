// Find the value of d<1000
//  for which 1/d
//  contains the longest recurring cycle in its decimal fraction part.

//output 983
//time taken=0.493 seconds
// i made a function where i check the remainder at each step and comparing with the array
// if i find the reminder being repeated once more i simply return the index at the length of numbers that time if not i m incrementing the index
#include <stdio.h>
#include <string.h>  

int find_recurring_cycle_length(int denominator) {
    int index = 0;
    int arr[1000];

    int numerator = 1;

    while (numerator != 0) {
        int quotient = numerator / denominator;   
        int remainder = numerator % denominator;  

        for (int i = 0; i < index; i++) {  
            if (arr[i] == remainder) {  
                return index;
            }
        }

        arr[index] = remainder; 
        index++;
        numerator = remainder * 10;  
    }

    return 0;
}

int main() {
    int longest_cycle = 0, best_denominator = 0;

    for (int i = 2; i <= 999; i++) {
        int cycle_length = find_recurring_cycle_length(i);
        if (cycle_length > longest_cycle) {
            longest_cycle = cycle_length;
            best_denominator = i;
        }
    }

    printf("Best denominator is %d\n", best_denominator);
    return 0;
}
