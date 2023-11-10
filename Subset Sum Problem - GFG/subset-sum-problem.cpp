//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int t[101][10001];
    bool helper(vector<int>&arr, int sum, int n){
        
        if(n == 0 && sum == 0)  return true;
        
        if(n == 0 && sum > 0)   return false;
        
        if(t[n][sum] != -1)     return t[n][sum];
        
        bool take = false, skip = false;
        
        if(arr[n - 1] <= sum){
            take = helper(arr, sum - arr[n - 1], n - 1);
        }
        
        skip = helper(arr, sum, n - 1);
        
        return t[n][sum] = (take || skip);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        memset(t, -1, sizeof(t));
        return helper(arr, sum, n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends