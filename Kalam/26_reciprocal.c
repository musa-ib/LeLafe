/*
Q .Find the integer d (where 1 < d < 1000) for which the decimal representation of 1/d contains the longest recurring cycle.

Functions:
cycleLength(d) -- Removes factors of 2 and 5 (since they don’t contribute to the cycle.
               -- Also finds smallest k
MainLoop: -- checks d from 2 to 999

Time Taken-- 0.505 sec

Time Compleity--
output-- 983






*/







#include <stdio.h>
#include <string.h>

// Function to compute the length of the repeating cycle in 1/d
int cycleLength(int d) {
    if (d == 1) return 0;  // 1/1 = 1.0 (no cycle)

    // Remove factors of 2 and 5 (they don't affect cycle length)
    while (d % 2 == 0) d /= 2;
    while (d % 5 == 0) d /= 5;

    if (d == 1) return 0;  // No cycle if only 2s and 5s remain

    // Find the smallest k where 10^k ≡ 1 mod d
    int remainder = 10 % d;
    int k = 1;
    while (remainder != 1) {
        remainder = (remainder * 10) % d;
        k++;
        if (k > d) return 0;  // Avoid infinite loops (anyways d > k always)
    }
    return k;
}

int main() {
    int max_cycle = 0;
    int best_d = 0;

    for (int d = 2; d < 1000; d++) {
        int current_cycle = cycleLength(d);
        if (current_cycle > max_cycle) {
            max_cycle = current_cycle;
            best_d = d;
        }
    }

    printf("The number d < 1000 with the longest recurring cycle is: %d\n", best_d);

    return 0;
}