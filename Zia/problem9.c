// There exists exactly one Pythagorean triplet for which a+b+c=1000
// .
// Find the product abc
// . output=31875000
//time taken 3.822 seconds

//i ran a loop on a b and c and checking the pythagoras condition and and a+b+c=1000 on each condition.
// once my condition is satisfied i multiplied the values of a,b and c



#include <stdio.h>

int main()
{
  int a;
  int b;
  int c;
  for (a = 1; a <= 1000; a++)
  {
    for (b = 2; b <= 1000; b++)
    {
      for (c = 3; c <= 1000; c++)
      {
        if (a + b + c == 1000 && c * c == a * a + b * b)
        {
          printf("values of a b and c are %d %d %d\n", a, b, c);
          printf("product is %d\n", a * b * c);
        }
      }
    }
  }
  return 0;
}
