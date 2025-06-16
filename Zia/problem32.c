// Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1
//  through 9
//  pandigital.

// HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
//there are two cases   ✅ Case 1: 1-digit × 4-digit = 4-digit and case 2 2-digit × 3-digit = 4-digit
//so i iterated through all the cases and found the product and then extraccted the dgits i put the digits in an array and looped two times on the same arraychecking
// do the digits repeat if yes return fallse otherwise put the produt in another array then looped on that array tooo in order to find whether
//the products repeat those who do not repeat i added the products t the sum.
#include <stdio.h>
#include <stdbool.h>

int findProduct(int num1, int num2) {
    return num1 * num2;
}

bool isPandigitalNumber(int x, int y, int z) {
    int digits[9];
    int index = 0;

    bool storeDigits(int num) {
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0) return false;
            digits[index++] = digit;
            num /= 10;
        }
        return true;
    }

    if (!storeDigits(x) || !storeDigits(y) || !storeDigits(z)) return false;
    if (index != 9) return false;

    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (digits[i] == digits[j]) return false;
        }
    }

    return true;
}

int main() {
    int sum = 0;
    int foundProducts[100] = {0};
    int count = 0;

    // ✅ Case 1: 1-digit × 4-digit = 4-digit
    for (int multiplicand = 1; multiplicand <= 9; multiplicand++) {
        for (int multiplier = 1111; multiplier <= 9999; multiplier++) {
            int product = findProduct(multiplicand, multiplier);
            if (isPandigitalNumber(multiplicand, multiplier, product)) {
                bool duplicate = false;
                for (int i = 0; i < count; i++) {
                    if (foundProducts[i] == product) {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate) {
                    foundProducts[count++] = product;
                    sum += product;
                    printf("✓ Unique digits found! %d × %d = %d\n", multiplicand, multiplier, product);
                }
            }
        }
    }

    // ✅ Case 2: 2-digit × 3-digit = 4-digit
    for (int multiplicand = 11; multiplicand <= 99; multiplicand++) {
        for (int multiplier = 100; multiplier <= 999; multiplier++) {
            int product = findProduct(multiplicand, multiplier);
            if (isPandigitalNumber(multiplicand, multiplier, product)) {
                bool duplicate = false;
                for (int i = 0; i < count; i++) {
                    if (foundProducts[i] == product) {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate) {
                    foundProducts[count++] = product;
                    sum += product;
                    printf("✓ Unique digits found! %d × %d = %d\n", multiplicand, multiplier, product);
                }
            }
        }
    }

    printf("\n✅ Final Sum of all unique products: %d\n", sum);
    return 0;
}
