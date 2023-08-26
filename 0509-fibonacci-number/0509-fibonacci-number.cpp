class Solution {
public:
    int fib(int n) {
        
        if(n <= 1)  return n;
        
        vector<int>dp(3, 0);
        
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        
        for(int i = 2; i <= n; i++){
            
            dp[2] = dp[0] + dp[1];
            
            dp[0] = dp[1];
            
            dp[1] = dp[2];
            
        }
        
        return dp[2];
        
    }
};