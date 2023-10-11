class Solution {
public:
    vector<int> PrevSmaller(vector<int>& arr, int n){
        
        vector<int>ans(n);
        stack<int>st;
        
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
    
    vector<int> NextSmaller(vector<int>& arr, int n){
        vector<int>ans(n);
        stack<int>st;
        
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
    int largestRectangleArea(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int>ps = PrevSmaller(arr, n);
        vector<int>ns = NextSmaller(arr, n);
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            int curr = (ns[i] - ps[i] - 1) * arr[i];
            
            ans = (ans < curr) ? curr : ans;
            
        }
        
        return ans;
        
    }
};