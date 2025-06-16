// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
// output=summm of square = 338350
// sum from 1 to 100 = 5050
// squae of sum = 25502500
// difference = 25164150
// time taken=0.644 seconds
// i found the square of all numbers first then summ them and then found the sum then squared it and then subtracted the both

#include <stdio.h>

int main()
{

  int i;
  int j = 0;
  int k = 0;
  int l;
  int difference;
  for (i = 1; i <= 100; i++)
  {
    j += i * i;
    k += i;
  }
  printf("summm of square = %d\n", j);

  printf("sum from 1 to 100 = %d\n", k);
  l = k * k;
  printf("squae of sum = %d\n", l);
  difference = l - j;
  printf("difference = %d\n", difference);
}
