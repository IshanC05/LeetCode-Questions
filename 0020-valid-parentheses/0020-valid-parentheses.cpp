class Solution {
public:
    bool isValid(string s) {
        if(!s.size()){
            return true;
        }
        stack<char>st;
        for(char x : s){
            if(x == '(' || x == '{'||x=='['){
                st.push(x);
            }else if(x == ')' and !st.empty() and st.top() == '('){
                st.pop();
            }else if(x == ']' and !st.empty() and st.top() == '['){
                st.pop();
            }else if(x == '}' and !st.empty() and st.top() == '{'){
                st.pop();
            }else{
                return false;
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};