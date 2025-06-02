#include <stdio.h>
int countDivisors(int num)
{
    int count = 0;
    int limit = (int)sqrt(num);
    for (int j = 1; j <= num; j++)
    {
        {
            if (j * j == num)
                count += 1;
            else
                count += 2;
        }
    }
    return count;
}

int main()
{
    for (int i = 1; i < 100000; i++)
    {
        int triangular_number = i * (i + 1) / 2;
        int divisors = countDivisors(triangular_number);

        if (divisors == 500)
        {
            printf("First triangular number with 500 divisors is %d ", triangular_number);
            break;
        }

    }
    return 0;
}
