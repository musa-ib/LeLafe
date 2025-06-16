// What is the index of the first term in the Fibonacci sequence to contain 
// 1000 digits?
//there is a mathematical formula which says in order to find the index of a fibnocii number 
//that has specific number of digits we shoul find
//Number of digits of F(n) = ⌊ n × log₁₀(ϕ) − log₁₀(√5) ⌋ + 1

// Where:

// ϕ = (1 + √5) / 2 ≈ 1.61803     ← Golden Ratio

// log₁₀(ϕ) ≈ 0.20899             ← log base 10 of golden ratio

// log₁₀(√5) ≈ 0.34949           ← log base 10 of square root of 5
//output 4782
// time 0.631
#include <stdio.h>
#include <math.h>

int main() {
    // Golden ratio
    double phi = (1 + sqrt(5)) / 2;
    double log_phi = log10(phi);
    double log_sqrt5 = 0.5 * log10(5);

    int n = 1;
    double digits;

    while (1) {
        digits = n * log_phi - log_sqrt5;
        if ((int)digits + 1 >= 1000) {
            break;
        }
        n++;
    }

    printf("Index of first Fibonacci number with 1000 digits: %d\n", n);
    return 0;
}

