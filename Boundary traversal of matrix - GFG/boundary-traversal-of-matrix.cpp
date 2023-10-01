//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        int right = 0;      // Starting column
        int down = 0;       // Starting row
        int left = m - 1;   // Ending column
        int top = n - 1;    // Ending row
    
        vector<int> ans;
    

            // Traverse right
            for (int j = right; j <= left; j++) {
                ans.push_back(matrix[down][j]);
            }
            down++; // Move down one row
    
            // Traverse down
            for (int i = down; i <= top; i++) {
                ans.push_back(matrix[i][left]);
            }
            left--; // Move left one column
    
            // Check if there are more rows to traverse
            if (down <= top) {
                // Traverse left
                for (int j = left; j >= right; j--) {
                    ans.push_back(matrix[top][j]);
                }
                top--; // Move up one row
            }
    
            // Check if there are more columns to traverse
            if (right <= left) {
                // Traverse up
                for (int i = top; i >= down; i--) {
                    ans.push_back(matrix[i][right]);
                }
                right++; // Move right one column
            }
    
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends