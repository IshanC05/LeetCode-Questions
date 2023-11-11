//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    vector<int> subsetSum(int arr[], int sum, int n){
        
        vector<vector<int>>t(n + 1, vector<int>(sum + 1, -1));
        
        for(int i = 0; i <= n; i++)
            t[i][0] = 1;
            
        for(int j = 1; j <= sum; j++)
            t[0][j] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                
                t[i][j] = t[i - 1][j];
                
                if(arr[i - 1] <= j){
                    
                    t[i][j] = max(t[i - 1][j], t[i - 1][j - arr[i - 1]]);
                    
                }
                
            }
        }
        
        return t[n];
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    
	    for(int i = 0; i < n; i++)
	        sum += arr[i];
	    
	    vector<int>row = subsetSum(arr, sum, n);
	    
	    int minSum = INT_MAX;
	    
	    for(int i = 0; i <= sum / 2; i++){
	        
	        if(row[i] == 1){
	            
	            minSum = min(minSum, abs(sum - 2*i));
	            
	        }
	        
	    }
        
        return minSum;
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends