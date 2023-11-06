//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int dp[1001][1001];
    
    long long int countPS(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
    
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
    
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 3;
            } else {
                dp[i][i + 1] = 2;
            }
        }
    
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
    
                if (s[i] != s[j]) {
                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + mod) % mod;
                } else {
                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % mod;
                }
            }
        }
    
        return dp[0][n - 1] % mod;
    }

     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends