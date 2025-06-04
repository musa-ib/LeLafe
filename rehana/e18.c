#include <stdio.h>
/*
This program finds the maximum total from top to bottom of a triangle of numbers using a bottom-up dynamic programming approach
Variables:
triangle[15][15] : 2D array that stores the given triangle of numbers
i,j: Loop for rows and col of the triangle
left,right: vars to hold the left and right value of nodes
Logic:
i started from the second last row of the triangle and moved upwards
For each element, i find the maximum of its two children & add that to the current element
till we reach top triangle[0][0] contains the maximum total value
Output:maximum total is 1074
Time Taken:O(n^2),n is no. of rows
*/


int main(){
    // triangle of numbers
    int triangle[15][15]={
        {75}, {95, 64}, {17, 47, 82}, {18, 35, 87, 10}, {20, 4, 82, 47, 65},
        {19, 1, 23, 75, 3, 34}, {88, 2, 77, 73, 7, 63, 67},
        {99, 65, 4, 28, 6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
    };
// Start from the second last row and go upwards
    for(int i=13;i>=0;i--){
        for(int j=0;j<=i;j++){
            // Choose the greatest of the two paths below
            int left=triangle[i+1][j];
            int right=triangle[i+1][j+1];
            //add that nodes value to root at current level  which is greater than other node below
            triangle[i][j]+=(left>right)?left:right;
        }
    }
// maximum result is stored at the topmost element
    printf("maximum total is %d ",triangle[0][0]);
    
}
