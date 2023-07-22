//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
// 	return 0 --> if pow < m
//  return 1 --> if pow == m
//  return 2 --> if pow > m
	
	int helper(int a, int b, int target){
	    
	    long long ans = 1;
	    
	    for(int i = 1; i <= b; i++){
	        
	        ans = ans * a;
	        
	        if(ans > target)    return 2;
	        
	    }
	    
	    if(ans == target)   return 1;
	    
	    return 0;
	    
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int start = 1, end = m;

	    while(start <= end){
	        
	        int mid = start + (end - start)/2;
            
            int calc = helper(mid, n, m);
            
	        if(calc == 1) return mid;

	        if(calc == 0) start = mid + 1;
	        
	        else end = mid - 1;
	    }

	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends