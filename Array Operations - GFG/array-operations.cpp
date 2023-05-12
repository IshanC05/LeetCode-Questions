//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int zCount = 0, ans = 0;
        int i = 0;
        stack<int>st;
        while(i < n){
            if(arr[i] != 0){
                st.push(arr[i]);
            }else{
                ++zCount;
                if(!st.empty()){
                    ++ans;
                    while(!st.empty()){
                        st.pop();
                    }
                }
                // ++i;
                // continue;
            }
            ++i;
        }
        if(!st.empty()){
            ++ans;
        }
        if(zCount == 0){
            return -1;
        }
        if(zCount == n){
            return 0;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends