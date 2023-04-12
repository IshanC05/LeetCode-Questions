class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cur=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push('(');
                ++cur;
                ans = max(ans, cur);
            }else if(s[i] == ')'){
                st.pop();
                --cur;
            }else{
                continue;
            }
        }
        return max(ans, cur);
    }
};