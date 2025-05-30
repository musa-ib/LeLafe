//Q. Find the first triangle number that has over 500 divisors.
#include <stdio.h>
#include <math.h>
//function to count the divisors
int count_div(int num){
int count = 0;
int sqrt_num = sqrt(num);

 for (int i = 1; i <= sqrt_num; i++) {
 if (num % i == 0) {
     count += (i == num / i) ? 1 : 2;
        }
    }

    return count;
}

int main()
{
int n = 1;
int limit = 500;

    while(1)
    {
 int triangle_number = n * (n + 1) / 2;// basically sums the first n natural numbers
int div_count = count_div(triangle_number);

    if (div_count > limit) {
     printf("First 10 digits %d\n", limit, triangle_number);
break;
        }

n++;
    }

    return 0;

}