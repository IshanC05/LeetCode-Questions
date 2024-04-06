class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        vector<bool> skip(n, false);
        
        stack<pair<char, int>> st;
        
        for(int i = 0; i < n; i++){
            
            char c = s[i];
            
            if(c >= 'a' && c <= 'z')    
                continue;
            
            else if(c == '(')
                st.push({c, i});
            
            else{
                
                if(st.empty())    
                    skip[i] = true;
                
                else if(st.top().first == '(')
                    st.pop();
            }
        }
        
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            skip[p.second] = true;
        }
        
        string res;
        
        for(int i = 0; i < n; i++){
            if(!skip[i])    res.push_back(s[i]);
        }
        
        return res;
    }
};