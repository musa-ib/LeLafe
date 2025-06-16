#include <stdio.h>

int main() {
    int a = 12, b = 18, hcf;

    // Find the smaller of a and b
    int min = (a < b) ? a : b;

    for (int i = 1; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            hcf = i;
        }
    }

    printf("HCF (GCD) of %d and %d is %d\n", a, b, hcf);

    return 0;
}
