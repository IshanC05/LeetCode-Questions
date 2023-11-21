//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

int t[1001][1001];
int helper(string &x, string &y, int n, int m){
    
    if(n == 0 || m == 0)    return 0;
    
    if(t[n][m] != -1)   return t[n][m];
    
    if(x[n - 1] == y[m - 1])
        return  t[n][m] = 1 + helper(x, y, n - 1, m - 1);
        
    return t[n][m] = helper(x, y, n - 1, m);
    
}
int maxSubsequenceSubstring(string X, string Y, int N, int M){
    //code
    memset(t, -1, sizeof(t));
    
    int maxL = 0;
    
    for(int i = 0; i <= M; i++){
    
        int smallAns = helper(X, Y, N, i);
    
        maxL = max(maxL, smallAns);
    }
    
    return maxL;
}