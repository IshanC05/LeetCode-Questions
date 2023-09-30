class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        int num3 = INT_MIN;
        stack<int>st;
        
        st.push(nums[n - 1]);
        
        for(int i = n - 2; i >= 0; i--){
            
            if(nums[i] < num3)  return true;
            
            while(!st.empty() && st.top() < nums[i]){
                num3 = max(num3, st.top());
                st.pop();
            }
            
            st.push(nums[i]);
            
        }
        
        return false;        
    }
};