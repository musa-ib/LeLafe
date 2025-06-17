//An irrational decimal fraction is created by concatenating the positive integers:

//0.12345678910111213141516...

//It can be seen that the 12th digit of the fractional part is 1.

//If dₙ represents the nᵗʰ digit of the fractional part, find the value of the following expression:
//d1 × d10 × d100 × d1000 × d10000 × d100000


//output=210
//time taken=1.18 second
// i looped over a char array extracted the string and put it into number array converting string to number after that 
//i made a function find product which is taking the number array as an argument find the values at specific index and multiplying them 
// i found answer

#include <stdio.h>
#include <string.h>
int findProduct(int array[], int size)
{
    int D1 = array[0];
    int D10 = array[9];
    int D100 = array[99];

    int D1000 = array[999];
    int D10000 = array[9999];
    int D100000 = array[99999];

    int answer = D1 * D10 * D100 * D1000 * D10000 * D100000;
    return answer;
}

int main()
{
    char str[8];
    static int arr[6000000];
    int index = 0;

    for (int i = 1; i <= 1000000; i++)
    {
        sprintf(str, "%d", i);

        for (int j = 0; j < strlen(str); j++)
        {
            arr[index++] = str[j] - '0';
        }
    }

    int result = findProduct(arr, index);
    printf("Product = %d", result);
    return 0;
}
