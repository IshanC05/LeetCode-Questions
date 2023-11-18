//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>>t(m + 1, vector<int>(n + 1, 0));
        
        // for(int i = 0; i <= m; i++)
        //     t[i][0] = i;
            
        // for(int j = 0; j <= n; j++)
        //     t[0][j] = j;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if(X[i - 1] == Y[j - 1]){
                    
                    t[i][j] = 1 + t[i - 1][j - 1];
                    
                }else{
                    
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                    
                }
                
            }
        }
        
        return m + n - t[m][n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends