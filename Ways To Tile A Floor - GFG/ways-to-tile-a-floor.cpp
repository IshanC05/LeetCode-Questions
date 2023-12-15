//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int M = 1e9+7;
    long long t[100005];
    long long helper(long long n){
        if(n <= 2)  return n;
        if(t[n] != -1)  return t[n];
        return t[n] = (helper(n - 1) + helper(n - 2)) % M;
    }
    long long numberOfWays(long long N) {
        //code here
        memset(t, -1, sizeof(t));
        return helper(N);
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