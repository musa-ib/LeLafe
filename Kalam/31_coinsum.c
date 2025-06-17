/*
Q. Find the number of ways to make £2 (200p) using UK coin denominations: 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), £2 (200p).

   Approach- Dynamic Programming
   
    We use a dp array where dp[i] stores the number of ways to make amount i.

    Then Initialize dp[0] = 1 (one way to make 0p: no coins).
    Time Complexity- O(target*no of coins)
    Time Taken- 1.175 sec
    Output= 73682
*/





#include <stdio.h>

int coin_sums() {
    int target = 200;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int dp[201] = {0}; // dp[0] to dp[200]
    dp[0] = 1;//one way to make 0p or no coins
    
    for (int i = 0; i < num_coins; i++) {
        int coin = coins[i];
        // For each coin we  update dp for all amounts from the coins value up to 200p.
        for (int amount = coin; amount <= target; amount++) {
            dp[amount] += dp[amount - coin];// update rule 
        }
    }
    
    return dp[target];
}

int main() {
    int result = coin_sums();
    printf("%d\n", result);
    return 0;
}