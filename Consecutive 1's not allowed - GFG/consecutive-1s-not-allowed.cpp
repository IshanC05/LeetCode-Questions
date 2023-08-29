//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
// 	#define ll long long
	ll countStrings(int n) {
	    // code here
	    
	    vector<ll>dp(3, 0);
	    
	    dp[0] = 2, dp[1] = 3;
	    
	    int mod = 1e9+7;
	    
	    if(n == 1)  return dp[0];
	    
	    else if(n == 2) return dp[1];
	    
	    for(int i = 3; i <= n; i++){
	        
	        dp[2] = (dp[1] + dp[0]) % mod;
	        
	        dp[0] = (dp[1]) % mod;
	        
	        dp[1] = (dp[2]) % mod;
	        
	    }
	    
	    return (dp[2]) % mod;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends