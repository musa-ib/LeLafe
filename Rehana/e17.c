#include <stdio.h>
int letters(int n)
{
    int till19[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    int ten_ty[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

    if (n == 1000)
        return 11;

    int cnt = 0;
    if (n >= 100)
    {
        cnt += till19[n / 100] + 7;
        if (n % 100 != 0)
            cnt += 3;
        n %= 100;
    }

    if (n >= 20)
    {
        cnt += ten_ty[n / 10];
        cnt += till19[n % 10];
    }
    else
    {
        cnt += till19[n];
    }

    return cnt;
}

int main()
{
    int total = 0;
    for (int i = 1; i <= 1000; i++)
    {
        total += letters(i);
    }
    printf("Total letters used %d ", total);
}
