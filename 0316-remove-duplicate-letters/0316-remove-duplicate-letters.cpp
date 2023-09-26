class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        unordered_map<char, int>mp;
        
        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }
        
        vector<bool>seen(26, false);
        stack<char>st;
        
        char start = s[0];
        seen[s[0] - 'a'] = true;
        st.push(s[0]);
        
        for(int i = 1; i < n; i++){
            
            if(seen[s[i] - 'a'])    continue;
            
            while(!st.empty() && st.top() > s[i] && mp[st.top()] > i){
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            
            if(!seen[s[i] - 'a']){
                seen[s[i] - 'a'] = true;
                st.push(s[i]);
            }
            
        }
        
        string ans = "";
        
        if(st.empty())  return ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;        
    }
};