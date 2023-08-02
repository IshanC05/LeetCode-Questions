//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int n) 
    {
        // Your code goes here   
        
        if(n <= 1)  return n;

        int l = 1, h = 1e9, ans = 1e9;
    
        while(l <= h){
    
            long long mid = l + (h - l) / 2;
            
            long long square = mid * mid;
    
            if(square == n) return mid;
    
            else if(square > n) h = mid - 1;
    
            else{
    
                ans = mid;
    
                l = mid + 1;
    
            }
    
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends