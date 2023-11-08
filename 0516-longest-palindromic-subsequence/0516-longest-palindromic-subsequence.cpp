class Solution {
public:
    int lcs(string &s, string &t, int m, int n){
        
        int dp[1001][1001];
        
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i <= m; i++)
            dp[i][0] = 0;
        
        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else{
                    
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    
                }
                
            }
        }
        
        return dp[m][n];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = "";
        
        for(char i : s)     
            t.push_back(i);
        
        reverse(t.begin(), t.end());
        
        int n = s.size();
        
        return lcs(s, t, n, n);
    }
};