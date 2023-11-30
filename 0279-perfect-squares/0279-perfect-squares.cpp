class Solution {
public:
    int helper(vector<int>& coins, int n, int sum, vector<vector<int>>&t){
        
	    if(sum == 0)    return 0;
	    
	    if(n == 0)  return INT_MAX - 1;
        
        if(t[n][sum] != -1)     return t[n][sum];
	    
	    if(coins[n - 1] <= sum){
            
            int take = 1 + helper(coins, n, sum - coins[n - 1], t);
            
            int skip = helper(coins, n - 1, sum, t);
            
            return t[n][sum] = min(take, skip);            
        }
	        
	    return t[n][sum] = helper(coins, n - 1, sum, t);
	    
	}
    
    int numSquares(int n) {
        
        vector<int>squares;
        
        for(int i = 1; i*i <= n; i++){
            squares.push_back(i*i);
        }
        
        int N = squares.size();
        
        vector<vector<int>>t(N + 1, vector<int>(n + 1, -1));
        
        return helper(squares, N, n, t);
        
    }
};