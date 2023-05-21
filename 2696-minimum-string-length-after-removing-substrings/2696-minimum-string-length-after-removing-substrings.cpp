class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.top() == 'A' and s[i] == 'B'){
                    st.pop();
                    continue;
                }else if(st.top() == 'C' and s[i] == 'D'){
                    st.pop();
                    continue;
                }else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
};