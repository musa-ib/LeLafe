// What is the largest
// n-digit pandigital prime that exists?
// i looped from 1234567 to 7654321 8 padigital or 9 pandigital skipping because they are always divided by 3.
// so aafter looping i passed the number to the is prime function than those numbers that ae prime is sent to is pandigital funcion
// this function is converting number to string and stored in charr array thrn i looprd over the char array two times to check if number
// is pandigital or not.
//output=7654319
//time taken= 2.624second
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool isPandigital(int num)
{
    char str[8];
    sprintf(str, "%d", num);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
                return false;
        }
    }
    return true;
}

bool isPrime(long long number)
{
    long long limit = sqrt(number);
    for (long long i = 2; i <= limit; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int maxPandigitalPrime = 0;
    for (int i = 1234567; i <= 7654321; i++)
    {
        if (isPandigital(i))
        {
            if (isPrime(i))
            {
                if (i > maxPandigitalPrime)
                {
                    maxPandigitalPrime = i;
                }
            }
        }
    }

    if (maxPandigitalPrime > 0)
    {
        printf("pandigital number %d\n", maxPandigitalPrime);
    }
    return 0;
}
