/*
Q.

* Func1

* Func2




Time Complexity : 
Exexution Time :
Output:  



*/


#include <stdio.h>
#include <time.h>

int main()
{ 
    int first_day_of_prev_year = 1; 
    int days_of_prev_year = 365;
    int firstday_nextyear = days_of_prev_year % 7 + first_day_of_prev_year;
    int sunday_count = 0;

    int day_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//
   int next_month_first_day=2;
 
    printf("%d\n", firstday_nextyear);
    switch (firstday_nextyear)
    {
    case 0:
        printf("sunday\n");
        break;
    case 1:
        printf("monday\n");
        break;
    case 2:
        printf("tuesday\n");
        break;
    case 3:
        printf("wednesday\n");
        break;
    case 4:
        printf("thursday\n");
        break;
    case 5:
        printf("friday\n");
        break;
    case 6:
        printf("saturday\n");
        break;
    }

    for (int year = 1901; year <= 2000; year++)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            day_in_months[1] = 29;
        }
        else
        {
            day_in_months[1] = 28;
        }
        for (int month = 0; month < 12; month++)
        {

            // next_month_first_day=(current_month_first_day+days_in_month)mod7
            {
                if ((next_month_first_day) % 7 == 0)
                {
            printf("month %d of %d\n", month, year);

                    sunday_count++;
                }
               next_month_first_day = (next_month_first_day + day_in_months[month]) % 7;
            }
        }
    }
    printf("Total Sundays on 1st of the month: %d\n", sunday_count);


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

}

