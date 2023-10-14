class Solution {
public:
    int n;
    
    int dp[501][501];
    
    int helper(int idx, int left, vector<int>& cost, vector<int>& time){
        
        if(left <= 0)   return 0; // all walls painted
        
        if(idx >= n)    return 1e9; // invalid case
        
        if(dp[idx][left] != -1)     return dp[idx][left];
        
        int paintedI = cost[idx] + helper(idx + 1, left - 1 - time[idx], cost, time);
        
        int notPainted = helper(idx + 1, left, cost, time);
        
        return dp[idx][left] = min(paintedI, notPainted);        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
       
        n = cost.size();
        
        memset(dp, -1, sizeof(dp));
        
        return helper(0, n, cost, time);
    }
};