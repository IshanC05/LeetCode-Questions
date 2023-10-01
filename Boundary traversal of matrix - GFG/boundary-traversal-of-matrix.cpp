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
        // code here
        int right = 0;      // traverse cols -> start row
        int down = m - 1;   // traverse rows -> start col
        int left = n - 1;   // traverse cols -> end row 
        int top = 0;        // traverse rows -> end col
        
        vector<int>ans;
        
        for(int j = 0; j < m; j++){
            ans.push_back(matrix[right][j]);
        }
        
        for(int i = right + 1; i < n; i++){
            ans.push_back(matrix[i][down]);
        }
        
        if(left != right){
            for(int j = down - 1; j >= 0; j--){
                ans.push_back(matrix[left][j]);
            }
        }
        
        if(top != down){
            for(int i = left - 1; i > right; i--){
                ans.push_back(matrix[i][0]);
            }
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