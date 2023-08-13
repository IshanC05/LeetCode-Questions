//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        
        if(n == 1 || n == 2)  return 1;
        
        int mod = 1e9+7;
        
        long long a = 1, b = 1, c;
        
        for(int i = 3; i <= n; i++){
            
            c = (a + b) % mod;
            
            a = (b % mod);
            
            b = (c % mod);
            
        }
        
        return c;
        
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends