#include <stdio.h>
#include <time.h>

int main() {





    
int n = 20; 
unsigned long long grid[21][21];  

for (int i = 0; i <= n; i++) {
 grid[i][0] = 1;
grid[0][i] = 1;
    }

for (int i = 1; i <= n; i++) {
for (int j = 1; j <= n; j++) {
grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
}
    }
printf("Number of paths in a %dx%d grid: %llu\n", n, n, grid[n][n]);

    return 0;
}
