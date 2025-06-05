//Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
//abundant numbers are those numbers whose sum of diviors is greater than the number itself and non abundant numbers are the vice versa whose sum of divisors 
//is less tha numbers.
//i was supposed to find the sum of numbers who are not formed  as sum of abundant numbers;
//for that purpose i made a function isAbundant to check whether number is abundant or not if abundant i added the number in the array
//then i iterated on that array and checking which numbers are formed by adding the values of array and which not
//those numbers which are not formed by adding values of array i took those numbers and added them in total.

//output-4179871
//


#include <stdio.h>
#include <stdbool.h>
//function to check abundant numbers
bool isAbundant(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum > n;
}

int main() {
    int limit = 28123;
    int abundant[28123];
    int count = 0;

    for (int i = 1; i <= limit; i++) {
        if (isAbundant(i)) {
            abundant[count++] = i;
        }
    }

    int total = 0;

    for (int num = 1; num <= limit; num++) {
        bool canBeWritten = false;

        for (int i = 0; i < count; i++) {
            for (int j = i; j < count; j++) {
                if (abundant[i] + abundant[j] == num) {
                    canBeWritten = true;
                    break;
                }
            }
            if (canBeWritten)
                break;
        }

        if (!canBeWritten) {
            // printf("%d cannot be written as sum of two abundant numbers\n", num);
            total += num;
        }
    }

    printf("Final sum of all positive integres  not expressed as sum of two abundant numbers: %d\n", total);

    return 0;
}
