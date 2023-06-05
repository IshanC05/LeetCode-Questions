//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int ans = 0, n = s.size();
        int i = 0, j = 0, len = 0;
        unordered_map<char, int>mp;
        while (j < n) {
            if (mp.size() > k) {
                --mp[s[i]];
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                ++i;
                --len;
            } else {
                if (mp.size() == k) {
                    ans = max(ans, len);
                }
                ++mp[s[j]];
                ++len;
                ++j;
            }
        }
        if(mp.size() == k){
            ans = max(ans, len);
        }
        if(ans == 0){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends