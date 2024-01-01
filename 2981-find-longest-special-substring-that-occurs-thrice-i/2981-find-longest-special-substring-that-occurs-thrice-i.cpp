class Solution {
public:
    bool check(string s){
        if(s.size() == 1)   return true;
        
        char x = s[0];
        
        for(char i : s)     if(i != x)  return false;
        
        return true;
    }
    int maximumLength(string s) {
        int n = s.size();
        
        map<string, int>mp;
        
        for(int i = 0; i < n; i++){
            string t;
            for(int j = i; j < n; j++){
                t.push_back(s[j]);
                ++mp[t];
            }
        }
        
        int maxLen = -1;
        
        for(auto it : mp){
            int k = it.first.size();
            if(it.second >= 3 && check(it.first))   maxLen = max({maxLen, k});
        }
        
        return maxLen;
        
    }
};