class Solution {
public:
    int dp[10005];
    int helper(vector<int>& coins, int sum, int n){
        
        if(sum == 0)    return 0;
        
        if(dp[sum] != 0)    return dp[sum];
        
        int res = INT_MAX;
        
        for(int i = 0; i < n; i++){
            
            if(sum - coins[i] >= 0){
                
                int curr = helper(coins, sum - coins[i], n);

                if(curr != -1)  res = min(res, 1 + curr);   
                
            }
            
            else   break;
        }
              
        return dp[sum] = res == INT_MAX ? -1 : res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        
        memset(dp, 0, sizeof(dp));
        
        int n = coins.size();
        
        return helper(coins, amount, n);
    }
};