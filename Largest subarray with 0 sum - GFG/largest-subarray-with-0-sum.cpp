//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int prefix = 0, idx = 0, ans = 0;
        while(idx < n){
            prefix = prefix + A[idx];
            if(prefix == 0){
                ans = idx + 1;
            }else{
                if(mp.find(prefix) != mp.end()){
                    ans = max(ans, idx - mp[prefix]);
                }else{
                    mp[prefix] = idx;
                }    
            }
            ++idx;
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends