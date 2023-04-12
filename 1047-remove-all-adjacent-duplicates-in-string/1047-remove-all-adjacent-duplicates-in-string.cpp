class Solution {
public:
    string removeDuplicates(string s) {
        string ans= "";
        stack<char>st;
        st.push(s[s.size()-1]);
        for(int i=s.size()-2;i>=0;--i){
            if(st.empty()){
                st.push(s[i]);
            }else if(s[i] != st.top()){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};