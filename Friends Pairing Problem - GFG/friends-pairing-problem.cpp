//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int M = 1e9+7;
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long>dp(n + 1, 0);
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++){
            
            dp[i] = dp[i - 1];
            
            dp[i] = (dp[i] + ((i - 1) * dp[i - 2])%M)%M;
            
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
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends