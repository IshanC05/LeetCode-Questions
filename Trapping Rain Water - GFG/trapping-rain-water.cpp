//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        int l = arr[0], r = arr[n - 1];
        leftMax[0] = l;
        rightMax[n - 1] = r;
        for (int i = 1; i < n; i++)
        {
            l = max(l, arr[i]);
            leftMax[i] = l;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            r = max(r, arr[i]);
            rightMax[i] = r;
        }
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            res = res + min(leftMax[i], rightMax[i]) - arr[i];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends