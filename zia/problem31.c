// In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
// It is possible to make £2 in the following way:

// 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
// How many different ways can £2 be made using any number of coins?
// output- 73682
// time  taken-1.218 seconds
// i made the smaller example like amout is 20 and i m
// supposed to check it by using 1 stamp coin 2 stmap coin
// 5 step coin and 10 step coin
////we know the 1 comibation is only 1 10 rupee coin so ican say at that time
// the other coins are 0 like a,b,c loop,other condition is 2 5 stamp coins i
// can saty at that time b=2 and others are 0;i did all the iterations covering 1 ,2,5m,10 ruppee coins
// after analyzing the solution  i substitued the stamps/rupee with pence.

#include <stdio.h>

int countWays(int amount)
{
    int ways = 0;

    for (int a = 0; 200 * a <= amount; a++)
    {
        for (int b = 0; 100 * b + 200 * a <= amount; b++)
        {
            for (int c = 0; 50 * c + 100 * b + 200 * a <= amount; c++)
            {
                for (int d = 0; 20 * d + 50 * c + 100 * b + 200 * a <= amount; d++)
                {
                    for (int e = 0; 10 * e + 20 * d + 50 * c + 100 * b + 200 * a <= amount; e++)
                    {
                        for (int f = 0; 5 * f + 10 * e + 20 * d + 50 * c + 100 * b + 200 * a <= amount; f++)
                        {
                            for (int g = 0; 2 * g + 5 * f + 10 * e + 20 * d + 50 * c + 100 * b + 200 * a <= amount; g++)
                            {
                                for (int h = 0; 1 * h + 2 * g + 5 * f + 10 * e + 20 * d + 50 * c + 100 * b + 200 * a <= amount; h++)
                                {
                                    if ((200 * a + 100 * b + 50 * c + 20 * d + 10 * e + 5 * f + 2 * g + 1 * h) == amount)
                                    {
                                        ways++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return ways;
}

int main()
{
    int amount = 200;
    printf("Total ways are %d\n", countWays(amount));
    return 0;
}
