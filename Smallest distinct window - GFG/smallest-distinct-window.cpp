//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        
        unordered_set<char>charSet;
        
        for(int i : str)    charSet.insert(i);
        
        unordered_map<char,int>mp;
        
        int i = 0, j = 0, n = str.size(), ans = INT_MAX;
        
        while(j < n){
            
            ++mp[str[j]];
            
            while(charSet.size() == mp.size()){
                
                ans = min(ans, j - i + 1);
                
                --mp[str[i]];
                
                if(mp[str[i]] == 0) mp.erase(str[i]);
                
                ++i;
                
            }
            
            ++j;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends