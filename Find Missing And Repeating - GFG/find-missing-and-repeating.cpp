//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int>mp;
        
        int missing = -1, twice = -1; 
        
        for(int i : arr){
            
            if(mp.find(i) != mp.end())     twice = i;
            
            else    ++mp[i];
            
        }
        
        int i = 1;
        
        while(i <= n){
            
            if(mp.find(i) == mp.end()){  
                
                missing = i;
                
                break;
            }
            
            else    ++i;
            
        }
        
        return {twice, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends