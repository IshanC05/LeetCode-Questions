class Solution {
public:
    int t[301][5001];
    int helper(vector<int>& coins, int amount, int n){
    
        if(n == 0)  return amount == 0 ? 1 : 0;
        
        if(t[n][amount] != -1)  return t[n][amount];
        
        int res = 0;
        
        if(coins[n - 1] <= amount){
            
            res = helper(coins, amount - coins[n - 1], n) + helper(coins, amount, n - 1);
            
        }else{
            
            res = helper(coins, amount, n - 1);
            
        }
        
        return t[n][amount] = res;
        
    }
    
    int change(int amount, vector<int>& coins) {
       
        int n = coins.size();
        
        memset(t, -1, sizeof(t));
        
        return helper(coins, amount, n);        
    }
};