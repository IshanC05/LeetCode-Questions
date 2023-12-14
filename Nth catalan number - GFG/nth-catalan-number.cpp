//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        int M = 1e9+7;
        vector<long long>t(n + 1);
        
        t[0] = 1; t[1] = 1;
        
        for(int i = 2; i <= n; i++){
            
            t[i] = 0;
            
            for(int j = 0; j < i; j++){
                
                t[i] = (t[i] + (t[j] * t[i - 1 - j])%M)%M;
                
            }
            
        }
        
        return t[n];
        
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends