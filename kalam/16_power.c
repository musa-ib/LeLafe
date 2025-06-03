#include <stdio.h>

int main() {
    int digits[3500] = {1}, size = 1, sum = 0;

    for (int i = 0; i < 1000; i++) {
        int carry = 0;
        for (int j = 0; j < size; j++) {
            int val = digits[j] * 2 + carry;
            digits[j] = val % 10;
            carry = val / 10;
        }
        while (carry) {
            digits[size++] = carry % 10;
            carry /= 10;
        }
    }

    for (int i = 0; i < size; i++) sum += digits[i];

    printf("Sum of digits of 2^1000 = %d\n", sum);
    return 0;
}
