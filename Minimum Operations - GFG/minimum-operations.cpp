//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        vector<int>dp(n + 1);
        
        if(n == 1)  return 1;
        
        if(n == 2)  return 2;
        
        if(n == 3)  return 3;
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for(int i = 4; i <= n; i++){
            
            int c = (i % 2 == 0) ? dp[i / 2] : INT_MAX;
            
            dp[i] = 1 + min(dp[i - 1], c);
            
        }
        
        return dp[n];
    }   
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends