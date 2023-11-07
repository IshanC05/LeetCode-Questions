class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        
        int n = coins.size();
        
        vector<int>dp(amount + 1);
        
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            
            dp[i] = INT_MAX;
            
            for(int j = 0; j < n; j++){
                
                if(i - coins[j] >= 0){
                    
                    int tempAns = dp[i - coins[j]];
                    
                    if(tempAns != -1)   dp[i] = min(dp[i], 1 + tempAns);
                }
                
                else    break;
            }
            
            dp[i] = (dp[i] == INT_MAX) ? -1 : dp[i];
            
        }
        
        return dp[amount];
        
    }
};