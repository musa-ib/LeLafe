// For which value of  p<=1000
//, is the number of solutions maximised for right angled triangle?
// output=840
// time taken=1.716 secconds
// i made a loop from 1 to 1000 passing the perimeter value to checkHypotneuse function check hypotneuse function is checking the
// hypoteeuse condtion on the values of a b and c and checking the coun that on a given perimeter how many times the hypotneuse condition
// is fullfilled and returning that count and then putting the highest count in max count and putting that perimeter value in mx perimeter

#include <stdio.h>
int checkHypotneuse(int perimeter)
{
    int count = 0;
    for (int a = 1; a < perimeter; a++)
    {
        for (int b = 1; b < perimeter - a; b++)
        {
            int c = perimeter - a - b;
            if (a * a + b * b == c * c)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int maxCount = 0;
    int maxPerimeter = 0;
    for (int p = 1; p < 1000; p++)
    {
        int result = checkHypotneuse(p);
        if (result > maxCount)
        {
            maxCount = result;
            maxPerimeter = p;
        }
    }
    printf("%d %d", maxPerimeter, maxCount);
    return 0;
}