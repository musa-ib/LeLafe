//Evaluate the sum of all the amicable numbers under 10000
//output=31626
//time taken=0.537 seconds
// i first found the divisors of all numbers from 1 to 1000 putting the addition of all diviors in sum variable for the j iteration and then find the divisors of each sum found and adding them to put in 
//sum 2 variable and then checking the amicable condition that is if the sum of diviors of a number is equal to the sum of divisors of
//sum if yes add them and put them in total variable

#include <stdio.h>

int main()
{
    int number = 1000;
    int total = 0;

    for (int i = 1; i <= number; i++)
    {
        int sum = 0; 
        printf(" divisors of %d are: ", i);

        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                printf("%d ", j);
                sum += j;
            }
        }

        printf("| Sum = %d", sum);

        int sum2 = 0;
        for (int k = 1; k < sum; k++)  
        {
            if (sum % k == 0)
            {
                sum2 += k;
            }
        }

        if (sum2 == i && sum != i) {
            total += i;
                }

    }

    printf("\nFinal Total of all amicable numbers under 1000 is: %d\n", total);

    return 0;
}
