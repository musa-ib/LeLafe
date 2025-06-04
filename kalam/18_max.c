// # Problem
// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
//
// ''   3''
// ''  7 4''
// '' 2 4 6''
// ''8 5 9 3''
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom of the triangle below:
//
// ''                     75''
// ''                    95 64''
// ''                  17 47 82''
// ''                 18 35 87 10''
// ''               20 04 82 47 65''
// ''              19 01 23 75 03 34''
// ''            88 02 77 73 07 63 67''
// ''           99 65 04 28 06 16 70 92''
// ''         41 41 26 56 83 40 80 70 33''
// ''        41 48 72 33 47 32 37 16 94 29''
// ''      53 71 44 65 25 43 91 52 97 51 14''
// ''     70 11 33 28 77 73 17 78 39 68 17 57''
// ''   91 71 52 38 17 14 91 43 58 50 27 29 48''
// ''  63 66 04 68 89 53 67 30 73 16 69 87 40 31''
// ''04 62 98 27 23 09 70 98 73 93 38 53 60 04 23''


/** as we know that the second last node(second last row) is the parent of the child node(last row). 
We can use the dependency resolution to tackle our problem. 
Moreover the child node has the terminal values and are also the final values.
We could use those value as leverage to update the values of the parent nodes.
So we start the bottom up approach by comparing the values and updating them.

Time Complexity --- O(n2)
Space Complexity --- O(1)- 

*/



#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 15

int max(int a, int b){
return (a>b) ? a: b; 
}  // function to find the max of 2 numbers

int main(){
 int triangle[MAX_ROWS][MAX_ROWS]={  
        {75},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20, 4, 82, 47, 65},
        {19, 1, 23, 75, 3, 34},
        {88, 2, 77, 73, 7, 63, 67},
        {99, 65, 04, 28, 06, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        {04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}
 };// hard coded into 2D array

// MAX_ROWS - 2: Start from the second last row (because the last row has no children).
    for (int i = MAX_ROWS - 2; i >= 0; i--) {                //i >= 0: Goes all the way up to the top row.
    for (int j = 0; j <= i; j++) {                          
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);    /**we are updating each element in the current row (i) by 
            adding the maximum of its two children in the row below (i + 1).*/
        }
    }

    printf("sum %d\n", triangle[0][0]);
    return 0;
}

//output was ---> 1074