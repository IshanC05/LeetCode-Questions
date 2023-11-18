//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
    	int m = s1.size();
        int n = s2.size();
    
        vector<vector<int>>t(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if(s1[i - 1] == s2[j - 1]){
                    
                    t[i][j] = 1 + t[i - 1][j - 1];
                    
                }else{
                    
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                    
                }
                
            }
        }
            
        int lcs = t[m][n];
        int deletions = m - lcs;
        int insertions = n - lcs;
    
        return insertions + deletions;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends