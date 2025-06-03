
/**
 * Number Letter Counts
 * 
 * it counts the total number of letters used when writing numbers from 1 to 1000 in words.
 * we follow British English conventions including "and" for numbers like "one hundred and one".
 * 
 * Time Complexity: O(1) (since our process is  fixed range 1-1000)
 * Space Complexity: O(1)
 * 
 * Time to complete: approx(0.494 seconds)
 */


#include <stdio.h>
//first we hard code the basic values
const int units_length[] = {
    0, 3, 3, 5, 4, 4, 3, 5, 5, 4,  // 0-9
    3, 6, 6, 8, 8, 7, 7, 9, 8, 8    // 10-19
};

const int tens_length[] = {
    0, 0, 6, 6, 5, 5, 5, 7, 6, 6    // 0, 10-90  and (0,0) because it 10 is already in units place
};

int getNumberLetterCount(int num) {
if (num == 1000) {
 return 11; // "one thousand" = 3 + 8
    }

int letters = 0;
    if (num >= 100) {
     letters += units_length[num / 100] + 7; // "hundred" = 7
        num %= 100;
     if (num > 0) {
            letters += 3; // "and" = 3
        }
    }

    if (num >= 20) {
        letters += tens_length[num / 10];
        num %= 10;
        if (num > 0) {
            letters += units_length[num];
        }
    } else if (num > 0) {
        letters += units_length[num];
    }

    return letters;
}
//we add the total
int main() {
    int totalLetters = 0;
    for (int i = 1; i <= 1000; i++) {
        totalLetters += getNumberLetterCount(i);
    }
    printf("letters are: %d\n", totalLetters);
    return 0;
}



//output was ---> 21124


