/*
Find the maximum total from top to bottom of the triangle below:
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

Time compplexity = O(n^2)
Answer = 1074
*/

#include <stdio.h>

int main()
{

    int result[15]={04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23};
    int pyramid[15][15] = {{75}, {95, 64}, {17, 47, 82}, {18, 35, 87, 10}, {20, 4, 82, 47, 65}, {19, 1, 23, 75, 3, 34}, // 2D array to store tirangle
                           {88, 2, 77, 73, 7, 63, 67},
                           {99, 65, 4, 28, 6, 16, 70, 92},
                           {41, 41, 26, 56, 83, 40, 80, 70, 33},
                           {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
                           {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
                           {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
                           {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
                           {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
                           {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};

    // for (int i = 0; i < 15; i++)
    // {
    //     for (int j = 0; j < 15; j++)
    //     {
    //         printf("%d\t", pyramid[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 15 - 2; i >= 0; i--)
    { // Starting from 2nd last row
        for (int j = 0; j <= i; j++)
        { // Find the largest adjacent number in next row and add that to current elemnet
            result[j] = pyramid[i][j] + (result[j] >result[j + 1] ? result[j] : result[j + 1]);
        }
    }
//     printf("%d\n", pyramid[0][0]);
    printf("%d\n",result[0]);
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d\t", pyramid[i][j]);
        }
        printf("\n");
    }
}
