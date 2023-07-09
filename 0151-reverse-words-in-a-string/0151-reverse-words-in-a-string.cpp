class Solution {
public:
    string reverseWords(string s) {
        
        int i = 0, n = s.size();
        
        if(i == n)  return "";
        
        stack<char>st;
        
        string ans = "";
        
        while(i < n){
            
            while(i < n && s[i] == ' ')  ++i;
            
            if(i == n) break;
            
            while(i < n && s[i] != ' '){
                st.push(s[i++]);
            }
            
            if(ans != "")   st.push(' ');
            
            while(!st.empty()){
                
                ans.push_back(st.top());
                
                st.pop();
                
            }
            
        }
        
        while(!st.empty()){
            
            ans.push_back(st.top());
            
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};