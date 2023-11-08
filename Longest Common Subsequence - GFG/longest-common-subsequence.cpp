//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int dp[1001][1001];
    
    int helper(string &s, string &t, int m, int n){
        if(dp[m][n] != -1)  return dp[m][n];
        
        if(m == 0 || n == 0)    return dp[m][n] = 0;
        
        if(s[m - 1] == t[n - 1])
            return dp[m][n] = 1 + helper(s, t, m - 1, n - 1);
        
        int ans1 = helper(s, t, m - 1, n);
        int ans2 = helper(s, t, m, n - 1);
               
        return dp[m][n] = max(ans1, ans2);
    }
    
    int lcs(int m, int n, string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        
        return helper(s1, s2, m, n);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends