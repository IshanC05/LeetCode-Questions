class Solution {
public:
    int t[13][10001];
    int findLowestCoins(vector<int> &coins, int cur, int amount) {
        if (cur >= coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        if(t[cur][amount] != -1)   return t[cur][amount];
        
        int res = -1;
        if (coins[cur] > amount) {
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins, cur + 0, amount - coins[cur]);
            int doNotTakeCoin = 0 + findLowestCoins(coins, cur + 1, amount - 0);
            res = min(takeCoin, doNotTakeCoin);
        }
        return t[cur][amount] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int res = findLowestCoins(coins, 0, amount);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }
};