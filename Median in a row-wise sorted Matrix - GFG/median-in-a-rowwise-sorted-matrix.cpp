//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countSmaller(vector<int>&arr, int k){
        
        int l = 0, h = arr.size() - 1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(arr[mid] <= k)   l = mid + 1;
            
            else h = mid - 1;
            
        }
        
        return l;
        
    }

    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        
        int l = matrix[0][0], h = matrix[0][C - 1];
        
        for(int i = 1; i < R; i++){
            
            l = min(l, matrix[i][0]);
            
            h = max(h, matrix[i][C - 1]);
        }
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            int count = 0, target = (R * C) / 2;
            
            for(int i = 0; i < R; i++){
                count += countSmaller(matrix[i], mid);
            }
            
            if(count > target)  h = mid - 1;
            
            else l = mid + 1;
        }
        
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends