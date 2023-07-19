//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool equal(vector<int>&arr1, vector<int>&arr2){
        for(int i = 0; i < 26; i++){
            if(arr2[i] != 0){
                if(arr1[i] < arr2[i]){
                    return false;
                }
            }
        }
        return true;
    }
    string smallestWindow (string s, string t)
    {
        // Your code here
        if(s.size() < t.size()) return "-1";
        
        vector<int>freqT(26, 0), freqS(26, 0);
        
        for(char x : t) ++freqT[x - 'a'];
        
        int i = 0, j = 0, n = s.size();
        string ans = "";
        int l = INT_MAX;
        
        while(j < n){
            ++freqS[s[j] - 'a'];
            while(equal(freqS, freqT)){
                int curr = j - i + 1;
                if(l > curr){
                    l = curr;
                    ans = s.substr(i, curr);
                }
                --freqS[s[i] - 'a'];
                ++i;
            }
            ++j;
        }
        
        ans = ans == "" ? "-1" : ans;
        
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends