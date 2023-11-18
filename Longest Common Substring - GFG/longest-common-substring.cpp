//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        // your code here
        vector<vector<int>>t(m + 1, vector<int>(n + 1, 0));
        
        int res = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if(S1[i - 1] == S2[j - 1]){
                    
                    t[i][j] = 1 + t[i - 1][j - 1];
                    
                }else{
                    
                    t[i][j] = 0;
                    
                }
                
                res = max(res, t[i][j]);
                
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends