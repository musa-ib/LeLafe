/*
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
Answer = 171
Time complexity = O(n);
*/

#include<stdio.h>
#include<stdbool.h>

//Function to check year is leap or not
bool IsLeap(int year){
    if(year%400==0)return true;// if year is divisible by 400 then leap year
    if(year%100==0)return false;// if divisible by 100 but not 400 then not a leap year
    if(year%4==0)return true;//if not a century and divisible by 4 then leap year

    return false;
}

int main(){
    int day = 1; // day = 0->sunday,1->mon... Given first day of 1900 is monday so days=1
    int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int count_sun = 0; //counts sundays
    for(int year=1900;year<=2000;year++){
        month_days[1] = (IsLeap(year)?29:28); // if year is leap feb has 29 days else 28
        for(int month=0;month<12;month++){
            // first day and 28 th day are same and remaining number will be the first day of next month
            day = (day + month_days[month])%7;
            if(day == 0 && year>1900){
                count_sun++;    // if day=0 which is sunday increment the counter
            }
        }
    }
    printf("%d",count_sun);
}