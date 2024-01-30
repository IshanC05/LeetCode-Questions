class Solution {
public:
    bool isOperator(string s){
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }
    string helper(string a, string b, string op){
        int x = stoi(a);
        int y = stoi(b);
        
        int res;
        
        if(op == "+")   res = x + y;
        if(op == "-")   res = x - y;
        if(op == "*")   res = x * y;
        if(op == "/")   res = x / y;
        
        return to_string(res);
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        
        for(int i = 0; i < tokens.size(); i++){
            if(!isOperator(tokens[i])){
                st.push(tokens[i]);
            }else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                
                string res = helper(s2, s1, tokens[i]);
                st.push(res);
                
            }
        }
        
        return stoi(st.top());
    }
};