class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26, -1);
        vector<bool>used(26, false);
        
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            last[s[i] - 'a'] = i;
        }
        
        stack<char>st;
        
        for(int i = 0; i < n; i++){
            
            if(used[s[i] - 'a'])    continue;
            
            while(!st.empty() && st.top() > s[i] && last[st.top() - 'a'] > i){
                used[st.top() - 'a'] = false;
                st.pop();   
            }
            
            if(!used[s[i] - 'a']){
                used[s[i] - 'a'] = true;
                st.push(s[i]);
            }
        }
        
        string res;
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};