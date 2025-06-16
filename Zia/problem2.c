// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
//  output-4613732
//  total fibnocci series numbers=33
//  time taken =0.313 seconds

#include <stdio.h>
int main()
{
    int a = 0;
    int b = 1;
    int c = 0;
    int sum = 0;
    int count = 0;

    while (c < 4000000)
    {
        c = a + b;
        a = b;
        b = c;

        if (c % 2 == 0)
        {
            sum += c;
        }
        count++;
    }
    printf(" Fibonacci numbers under 4 million: %d\n", count);

    printf("Sum of even Fibonacci numbers under 4 million: %d\n", sum);
    return 0;
}
