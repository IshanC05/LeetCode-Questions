//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long numberOfWays(long long n) {
        //code here
        long long mod = 1e9 + 7;
        long long dp[3] = {1,2,0};
        if(n < 3){
            return dp[n-1];
        }
        for(long long i=3;i<=n;i++){
            dp[2] = ((dp[0] % mod) + (dp[1] % mod)) % mod;
            dp[0] = (dp[1] % mod);
            dp[1] = (dp[2] % mod);
        }
        return (dp[2] % mod);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends