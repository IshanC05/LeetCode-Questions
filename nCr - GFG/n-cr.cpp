//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int M = 1e9+7;
    
    int t[1001][801];
    
    int helper(int n, int r){
        
        if(n < r)   return 0;
        
        if(n == r || r == 0)    return 1;
        
        if(t[n][r] != -1)   return t[n][r];
        
        int a = helper(n - 1, r - 1);
        
        int b = helper(n - 1, r);
        
        return t[n][r] = (a + b) % M;
        
    }
    
    int nCr(int n, int r){
        // code here
        memset(t, -1, sizeof(t));
        
        return helper(n, r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends