//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        
        int helper(int num){
            
            int res = 0;
            
            for(int i = 5; i <= num; i = i*5)   res += (num / i);
            
            return res;
        }
        
        int findNum(int n)
        {
        //complete the function here
            
            int l = 1, h = INT_MAX, ans = INT_MAX;
            
            while(l <= h){
                
                int mid = l + (h - l) / 2;
                
                int count = helper(mid);
                
                if(count >= n){
                    
                    ans = min(ans, mid);
                    
                    h = mid - 1;
                    
                }else   l = mid + 1;
                
            }
            
            return ans;
        
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends