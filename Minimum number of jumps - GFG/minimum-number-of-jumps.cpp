//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  
    bool isPossible(int* arr, int n){
        
        int goal = n - 1;
        
        for(int i = n - 2; i >= 0; i--){
            
            if(goal <= i + arr[i]){
                
                goal = i;
            }
            
        }
        
        return goal == 0;
        
    }
  
    int minJumps(int arr[], int n){
        // Your code here
        
        if(!isPossible(arr, n))     return -1;
        
        int l = 0, r = 0, ans = 0;
        
        while(r < n - 1){
            
            int farthest = 0;
            
            for(int i = l; i <= r; i++){
                
                farthest = max(farthest, i + arr[i]);
                
            }
            
            l = r + 1;
            
            r = farthest;
            
            ++ans;
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
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends