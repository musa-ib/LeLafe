#include <stdio.h>
#define MAX 500  

int multiply(int x, int res[], int size) {
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int product = res[i] * x + carry;
        res[i] = product % 10;  
        carry = product / 10;  
    }
    while (carry) {
        res[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

int main() {
    int res[MAX];
    res[0] = 1;
    int size = 1;  

    for (int i = 2; i <= 100; i++) {
        size = multiply(i, res, size);
    }

    int count[10] = {0};
    for (int i = 0; i < size; i++) {
        count[res[i]]++;
    }

    printf("100! = ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    printf("\n");

   
printf("Digit frequencies in 100!:\n");
for (int i = 0; i < 10; i++) {
    printf("%d : %d\n", i, count[i]);
}

int sum = 0;
for (int i = 0; i < size; i++) {
    sum += res[i];
}
printf("Sum of digits in 100! = %d\n", sum);
    return 0;
}
