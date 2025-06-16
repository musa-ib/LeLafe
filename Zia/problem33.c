// The fraction 49/98
//  is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98=4/8
// , which is correct, is obtained by cancelling the
// s.

// We shall consider fractions like, 30/50=3/5
// , to be trivial examples.

// There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

// If the product of these four fractions is given in its lowest common terms, find the value of the denominator.


//otput=100
//time taken=0.772 scond
//i first found the all possible two digit numerators and denominators and extracted the digits of them  check is the any repetition
//of the digits in the numerator and denominator if yes divide both the didgits and checked if the answer is euqual to the divison of actual numbers
//if yes stored them in the product numerator and denomminator and then found the hcf of two num and denominator and divided the number by hcf 
#include <stdio.h>
#include <stdbool.h>

int allPossibleCombinatiosOfNumeratorDenominator(int first, int second)
{
    return first * 10 + second;
}

bool isCheckNumeratorLessThanDenominator(int numerator, int denominator)
{
    return numerator < denominator;
}
bool isCheckNonTrivialFunction(int numerator, int denominator)
{
    int n1 = numerator / 10;
    int n2 = numerator % 10;
    int d1 = denominator / 10;
    int d2 = denominator % 10;

    if (n2 == 0 && d2 == 0) return false;

    float original = (float)numerator / denominator;

    if (n1 == d1  && (float)n2 / d2 == original) return true;
    if (n1 == d2   && (float)n2 / d1 == original) return true;
    if (n2 == d1  && (float)n1 / d2 == original) return true;
    if (n2 == d2 && (float)n1 / d1 == original) return true;

    return false;
}
int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int productNumerator = 1;
    int productDenominator = 1;
    for (int firstDigitOfNumerator = 1; firstDigitOfNumerator <= 9; firstDigitOfNumerator++)
    {
        for (int secondDigitOfNumerator = 0; secondDigitOfNumerator <= 9; secondDigitOfNumerator++)
        {
            int numerator = allPossibleCombinatiosOfNumeratorDenominator(firstDigitOfNumerator, secondDigitOfNumerator);
            // printf("All possible numerator found: %d\n", numerator);

            for (int firstDigitOfDenominator = 1; firstDigitOfDenominator <= 9; firstDigitOfDenominator++)
            {
                for (int secondDigitOfDenominator = 0; secondDigitOfDenominator <= 9; secondDigitOfDenominator++)
                {
                    int denominator = allPossibleCombinatiosOfNumeratorDenominator(firstDigitOfDenominator, secondDigitOfDenominator);
                    // printf("All possible denominator found: %d\n", denominator);

                    if (isCheckNumeratorLessThanDenominator(numerator, denominator))
                    {
                        if (isCheckNonTrivialFunction(numerator, denominator))
                        {
                            printf("Curious fraction found: %d/%d\n", numerator, denominator);
                            productNumerator *= numerator;
                            productDenominator *= denominator;
                        }
                    }
                }
            }
        }
    }
int hcf = findHCF(productNumerator, productDenominator);
    int reducedNumerator = productNumerator / hcf;
    int reducedDenominator = productDenominator / hcf;

    printf("\nFinal product in lowest terms: %d/%d\n", reducedNumerator, reducedDenominator);
    printf("Answer (denominator only): %d\n", reducedDenominator);
    return 0;
}
