//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> PrevSmaller(long long *arr, int n){
        
        vector<long long>ans(n);
        stack<long long>st;
        
        st.push(0);
        ans[0] = -1;
        
        for(int i = 0; i < n; i++){
            
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if(st.empty())
                ans[i] = -1;
                
            else    ans[i] = st.top();
            
            st.push(i);
        }
        
        return ans;
    }
    
    vector<long long> NextSmaller(long long *arr, int n){
        vector<long long>ans(n);
        stack<long long>st;
        
        st.push(n - 1);
        ans[n - 1] = n;
        
        for(int i = n - 2; i >= 0; --i){
            
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if(st.empty())
                ans[i] = n;
                
            else    ans[i] = st.top();
            
            st.push(i);
        }
        
        return ans;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long>ps = PrevSmaller(arr, n);
        vector<long long>ns = NextSmaller(arr, n);
        
        long long ans = LONG_MIN;
        
        for(int i = 0; i < n; i++){
            
            long long curr = (ns[i] - ps[i] - 1) * arr[i];
            
            ans = (ans < curr) ? curr : ans;
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends