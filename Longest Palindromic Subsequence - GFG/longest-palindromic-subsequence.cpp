//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
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
    int longestPalinSubseq(string s) {
        //code here
        string t(s.rbegin(), s.rend());
        
        int n = s.size();
        
        return lcs(s, t, n, n);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends