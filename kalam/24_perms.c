 /*
Q. A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
The lexicographic permutations of 0, 1 and 2 are:
                        012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?




aLGORITHM;
1.Start with all digits in order [0,1,2,3,4,5,6,7,8,9]
2.Convert to 0-based index:subtract 1 from target
3.Determine each digit position by
    Calculating how many permutations start with each possible digit
    Slecting the appropriate digit
    Remove that digit from available digits
    Update the remaining position count.
4.Also repeat the steps until all digits are placed.







Time Complexity: 
Time Taken: 0.515 sec
Output: 2783915460




*/



#include <stdio.h>
#include <string.h>

// Function to calculate factorial
//Precomputes factorials needed for calculations
// eg.  9! = 362880, 8! = 40320, etc.
long factorial(int n) {
    long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to find the nth lexicographic permutation
// n=999999
/* now we take first digit (i=0).
remaining dits will be 10 so 
factorial 9=362880
idex will be 999999/362880=2
select the digit 2.
remove it .
New target position will be now = remainder = 274239
repeat for neext digit 8!=
till all digits are over
*/
void find_perms(int n) {
    char digits[] = "0123456789";
    int length = strlen(digits);
    char result[length + 1];
    result[length] = '\0';
    
    n--; // convert to 0-based index
    
    for (int i = 0; i < length; i++) {
        long fact = factorial(length - 1 - i);
        int index = n / fact;
        result[i] = digits[index];
        
        // Remove the used digit from the array
        for (int j = index; j < length - 1; j++) {
            digits[j] = digits[j + 1];
        }
        digits[length - 1] = '\0';
        
        n %= fact;
    }
    
    printf("millionth permutation is: %s\n", result);
}

int main() {
    find_perms(1000000);
    return 0;
}