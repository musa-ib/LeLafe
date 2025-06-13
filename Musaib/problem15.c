/*
Starting in the top left corner of a 2*2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20*20grid?
create a matrix grid of size 21*21 where each cell reprsent a node.
Time complexity = O(n^2)
Answer = 137846528820
*/

#include<stdio.h>

int main(){
    long long grid[21][21];//Creating a grid of size 21*21
    grid[0][0]=0;// intializing starting point with 0
    for(int i=1;i<21;i++){ // initializing first row and first column with 1 except starting point becauz every node in first row
                            // column can reached by left and top node respectively
        grid[0][i]=1;
        grid[i][0]=1;
    }

    

    for(int i=1;i<21;i++){
        for(int j=1;j<21;j++){
            grid[i][j] = grid[i-1][j]+grid[i][j-1];//current cell can be reached by two ways either from top or from left cell
        }
    }
    
    printf("%lld\n",grid[20][20]);
}