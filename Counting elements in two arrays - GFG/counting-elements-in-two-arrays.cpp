//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    
    int helper(int* arr2, int n, int k){
        
        int l = 0, h = n - 1;
        
        int count = 0;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(arr2[mid] <= k){
                
                count = mid + 1;
                
                l = mid + 1;
            }else{
                
                h = mid - 1;
                
                count = mid;
                
            }
            
        }
        
        return count;
        
    }
  
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    //Your code goes here
        sort(arr2, arr2 + n);
        
        vector<int>ans(m, 0);
        
        for(int i = 0; i < m; i++){
            
            ans[i] = helper(arr2, n, arr1[i]);
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends