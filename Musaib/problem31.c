/*
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
Answer = 73682
time complexity = O(n*t) where n =  no. of coins
and t = number which we have to make using n coins
*/

#include<stdio.h>

int main(){
    int coins[8]={1,2,5,10,20,50,100,200};// coins available
    int goal = 200; 
    int ways[201] = {0};//stores number of ways with which we can make a number with avialable coins
    ways[0]=1;// 0 can be achieved by one way i.e. no coin used

    
    for(int i=0;i<8;i++){
        for(int j=1;j<= goal;j++){
            if(coins[i]<=j)
            ways[j] = ways[j]+ways[j-coins[i]];//w[j] = no of ways j can be made using  coins 0- i-1,
                                               //ways[j-coins[i]] =  no of ways j can be made withcoin i

        }
    }
    printf("%d",ways[200]);
}