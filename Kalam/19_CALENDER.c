/**
Q. Count the suundays falling on 1st of the month (1901-2000)
  
 * Variables:
    day: Current day of the week (0=Sunday, 1=Monday, ..., 6=Saturday)
    month: Current month (1-12)
    year: Current year (1901-2000)
    sunday_count: Accumulates the number of Sundays on the 1st
  
 * Functions:
     is_leap_year(int year): Checks if a year is a leap year
     main(): Computes the day of the week for each 1st of the month
  
 * Output: Number of Sundays on the 1st of the month from 1901-2000: 171
 * Time Taken: ~0.5 secs
 */

#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if (year % 4 != 0) return false;
    else if (year % 100 != 0) return true;
    else return (year % 400 == 0);
}

int main() {
    int day = 2; // 1 Jan 1901 was Tuesday (since 1 Jan 1900 was Monday)
        int sunday_count = 0;

    for (int year = 1901; year <= 2000; year++) {
    for (int month = 1; month <= 12; month++) {

        // Check if current 1st is a Sunday (day == 0)


            if (day == 0) {
            sunday_count++;
            }

            // Compute days in current month
        int days_in_month;
            if (month == 2) {
                days_in_month = is_leap_year(year) ? 29 : 28;} 
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                days_in_month = 30;}
            else {
                days_in_month = 31;
            }

            // Update day for the next month
            day = (day + days_in_month) % 7;
        }
    }

    printf("No of sundays on the 1st of the month from 1901-2000: %d\n", sunday_count);
    return 0;

}