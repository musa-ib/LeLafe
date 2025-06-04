/*
This program counts how many Sundays fell on the first of the month during the 20th century
(i.e. from 1 Jan 1901 to 31 Dec 2000).
Variables:
d: Keeps track of the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday).
Starts at 1 because 1 Jan 1900 was a Monday.
cnt: Counter for how many times the 1st of a month is a Sunday (only from 1901 onward).
daysCnt: Array storing the number of days in each month (non-leap year format).
y,mo: Loops for year and month.

Function:
isLeapY(y): Returns 1 if the year `y` is a leap year, 0 otherwise.

Logic:
Loop from year 1900 to 2000 to correctly track days (though we count only from 1901).
For each month, check if the 1st day of that month is a Sunday (i.e., `d % 7 == 0`) and year is ≥ 1901.
If yes, increment the counter.
Update the day counter `d` by adding the number of days in that month.
For February (index 1) adjust to 29 days if the year is a leap year.

Output:
no. of sundays 171

Time Taken:
O(n), where n is the number of years 
*/


#include <stdio.h>

int isLeapY(int y){
    if (y%400==0) 
    {return 1;}
    if (y%100==0)
    { return 0;}
    if (y%4==0)
    { return 1;}
    
}

int main() {
    int d=1; // 1 Jan 1900 was Monday so 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    int cnt=0;
    int daysCnt[]={31,28,31,30,31,30,31,31,30,31,30,31};

    // Start from 1900 to get correct day later on 
    for (int y=1900;y<=2000;y++){
        for (int mo=0;mo<12;mo++){
            if (y>=1901 && d%7==0){
                cnt++;
            }

            int days=daysCnt[mo];
            if (mo==1 && isLeapY(y)){
                days=29;
            }

            d+=days;
        }
    }

    printf("no. of sundays %d ", cnt);
}
