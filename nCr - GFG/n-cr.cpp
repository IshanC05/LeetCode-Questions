//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(n < r)   return 0;
       
        int M = 1e9+7;
        
        vector<vector<int>>t(n + 1, vector<int>(r + 1));
        
        for(int i = 0; i <= n; i++){
            t[i][0] = 1;
        }
        
        for(int j = 1; j <= r; j++){
            t[0][j] = 0;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                
                if(j > i)   t[i][j] = 0;
                
                else if(i == j)     t[i][j] = 1;
                
                else    t[i][j] = (t[i - 1][j - 1] + t[i - 1][j]) % M;
            }
        }
        
        return t[n][r];
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