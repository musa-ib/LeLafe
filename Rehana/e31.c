/*program to find  different ways can £2 be made using any number of coins 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p)
i used array arr to no of ways to make from 0 to 200p ,i calculated using these 8 coins,how many possible ways
are there to make 200p .I used dynamic programming to store the value of p's 1p ,2p till 200 p inside
arr array and ran iteration for no of coins given i.e 8..then i found out arr[200] after i completed iterating
over all 8 coins that will give me the no of ways to write 200p using these 8 coins
TC O(e2*coinsCnt)
o/p no of ways to make 200p 73682

*/
#include <stdio.h>

int main() {
    int e2=200;  // p to represent using other 8 coins
    int coins[]={1, 2, 5, 10, 20, 50, 100, 200};
    int coinsCnt=sizeof(coins) / sizeof(coins[0]);

    int arr[201]={0};  // no of ways to write p in terms of ther 8 coins
    arr[0]=1;  // 1 way to make 0p  using no coins

    // go through each coin
    for(int i=0;i<coinsCnt;i++) {
        int coin=coins[i];

        // considering all 8 coins and going till e2 to see no of ways to represent this e2
        for (int j=coin;j<=e2;j++) {
            arr[j]+=arr[j-coin];// used DP  to store previous coins value also
        }
    }

    
    printf("no of ways to make 200p %d ",arr[200]);

   
}
