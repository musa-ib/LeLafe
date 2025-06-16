#include <stdio.h>
int countDivisors(int num)
{
    int count = 0;
    for (int j = 1; j <= num; j++)
    {
        if (num % j == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    for (int i = 1; i < 10000; i++)
    {
        int triangular_number = i * (i + 1) / 2;  
        int divisors = countDivisors(triangular_number);

        if (divisors == 500)
        {
            printf("First triangular number with 500 divisors is %d\n", triangular_number);
            break;
        }

    }
    return 0;
}
