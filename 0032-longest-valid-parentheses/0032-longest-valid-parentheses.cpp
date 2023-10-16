class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '(')     st.push(i);
            
            else{
                
                if(!st.empty() && s[st.top()] == '(')   st.pop();
                
                else    st.push(i);
            }
            
        }
        
        int ans = 0;
        int curr = s.size();
        
        while(!st.empty()){
            ans = max(ans, curr - st.top() - 1);
            curr = st.top();
            st.pop();
        }
        
        return max(ans, curr);
    }
};