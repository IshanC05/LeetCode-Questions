class Solution {
public:
    int t[13][10001];
    int helper(vector<int>& coins, int n, int sum){
        
	    if(sum == 0)    return 0;
	    
	    if(n == 0)  return INT_MAX - 1;
        
        if(t[n][sum] != -1)     return t[n][sum];
	    
	    if(coins[n - 1] <= sum){
            
            int take = 1 + helper(coins, n, sum - coins[n - 1]);
            
            int skip = helper(coins, n - 1, sum);
            
            return t[n][sum] = min(take, skip);            
        }
	        
	    return t[n][sum] = helper(coins, n - 1, sum);
	    
	}
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        memset(t, -1, sizeof(t));
        
        int res = helper(coins, n, amount);
        
        return res == INT_MAX - 1 ? -1 : res;
        
    }
};