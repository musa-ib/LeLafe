#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
if (n <= 1)
        return false;
    for (int i = 2; i<=sqrt(n); i++) {
    if (n % i == 0)
        return false;
    }
  return true;
}

int main() {
 int count = 0;
int n = 2;

 while (1) {
  if (isPrime(n)) {
        count++;
    if (count == 10001) {
      printf("%d\n", n); 
     break;
            }
        }
    n++;
    }

    return 0;
}
