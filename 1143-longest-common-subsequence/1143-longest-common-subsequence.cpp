class Solution {
public:
    int dp[1001][1001];
    int helper(string &s, string &t, int m, int n){
        
        if(m == 0 || n == 0)    return 0;
        
        if(dp[m][n] != -1)   return dp[m][n];
        
        if(s[m - 1] == t[n - 1])
            return dp[m][n] = 1 + helper(s, t, m - 1, n - 1);
        
        int ans1 = helper(s, t, m - 1, n);
        int ans2 = helper(s, t, m, n - 1);
        
        return dp[m][n] = max(ans1, ans2);        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        
        memset(dp, -1, sizeof(dp));
        
        return helper(text1, text2, m, n);
        
    }
};