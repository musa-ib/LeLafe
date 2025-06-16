#include <stdio.h>

int main() {
    int spiral[8][8] = {0};
    int top = 0, bottom = 7, left = 0, right = 7;
    int num = 1;

    // Fill the spiral
    while (num <= 64) {
        for (int i = left; i <= right; i++) spiral[top][i] = num++;
        top++;
        for (int i = top; i <= bottom; i++) spiral[i][right] = num++;
        right--;
        for (int i = right; i >= left; i--) spiral[bottom][i] = num++;
        bottom--;
        for (int i = bottom; i >= top; i--) spiral[i][left] = num++;
        left++;
    }

    // Print the matrix
    printf("Spiral Matrix (8x8):\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%3d ", spiral[i][j]);
        }
        printf("\n");
    }

    // Calculate diagonal sum
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += spiral[i][i];           // Main diagonal
        sum += spiral[i][7 - i];       // Secondary diagonal
    }

    // If n is even, no overlap. If odd, subtract center once (not needed for 8x8)
    printf("\nSum of diagonals: %d\n", sum);

    return 0;
}
