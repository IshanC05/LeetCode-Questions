class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        unordered_map<char, int>mp;
        
        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }
        
        vector<bool>seen(26, false);
        string ans = "";
        
        seen[s[0] - 'a'] = true;
        ans.push_back(s[0]);
        
        for(int i = 1; i < n; i++){
            
            if(seen[s[i] - 'a'])    continue;
            
            while(!ans.empty() && ans.back() > s[i] && mp[ans.back()] > i){
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            if(!seen[s[i] - 'a']){
                seen[s[i] - 'a'] = true;
                ans.push_back(s[i]);
            }
            
        }
        
        return ans;        
    }
};