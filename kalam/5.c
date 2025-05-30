#include <stdio.h>
// we use the euclidean algo to compute the gcd ...
   long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
         b = a % b;
        a = temp;
    }
    return a;
}
//the formulae to compute the lcm using gcd
 long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
// driver function//
//will accumulate the result of all the numbers upto 20
int main() {
    long long result = 1;

    for (int i = 2; i <= 20; i++) {
        result = lcm(result, i);
}

    printf("Num is: %lld\n", result);
return 0;
}
