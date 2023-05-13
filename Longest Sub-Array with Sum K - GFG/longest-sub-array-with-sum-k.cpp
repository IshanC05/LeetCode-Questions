//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int prefixSum = 0;
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            prefixSum = prefixSum + arr[i];
            if(prefixSum == k){
                ans = max(ans, i + 1);
            }
            if(mp.find(prefixSum - k) != mp.end()){
                ans = max(ans, i - mp[prefixSum - k]);
            }
            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;    
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends