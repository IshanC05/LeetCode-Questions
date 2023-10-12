//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minSteps(int N) 
	{ 
	    // Your code goes here
	    if(N == 1)
	        return 0;
	    
	    if(N <= 3)  
	        return 1;
	    
	    vector<int>dp(N + 1);
	    
	    dp[1] = 0;
	    dp[2] = 1;
	    dp[3] = 1;
	    
	    for(int i = 4; i <= N; i++){
	        int a = (i % 2 == 0) ? dp[i / 2] + 1 : INT_MAX;
	        int b = (i % 3 == 0) ? dp[i / 3] + 1 : INT_MAX;
	        
	        dp[i] = min(dp[i - 1] + 1, min(a , b));
	    }
	    
	    return dp[N];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends