//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[501][501];
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    
    int helper(string &s, int i, int j) {
        if (i >= j) {
            return 0;
        }
    
        if (isPalindrome(s, i, j)) {
            return t[i][j] = 0;
        }
        
        if(t[i][j] != -1)   return t[i][j];
        
        int minCuts = INT_MAX;
    
        for (int k = i; k < j; k++) {
            
            int left, right;
            
            if(t[i][k] == -1){
                left = helper(s, i, k);
                t[i][k] = left;
            }
            
            else   left = t[i][k];
            
            if(t[k + 1][j] == -1){
                right = helper(s, k + 1, j);
                t[k + 1][j] = right;
            }
            
            else   right = t[k + 1][j];
            
            int smallAns = 1 + left + right;
            minCuts = min(smallAns, minCuts);
        }
    
        return t[i][j] = minCuts;
    }
    
    int palindromicPartition(string str) {
        memset(t, -1, sizeof(t));
        return helper(str, 0, str.size() - 1);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends