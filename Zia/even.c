#include <stdio.h>

int main() {
    int array[] = {11, 22, 3, 14, 16, 91};
    int length;
    int sum = 0;

    length = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
        if (array[i] % 2 == 0) {
            sum += array[i];
        }
    }

    printf("Sum of even numbers: %d\n", sum);

    return 0;
}
