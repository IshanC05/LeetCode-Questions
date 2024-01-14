class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())    return false;
        
        vector<int>s(26, 0), t(26, 0);
        unordered_map<int, int>mp;
        
        for(char i : word1)
            ++s[i - 'a'];
        
        for(char j : word2){
            ++t[j - 'a'];
        }
        
        for(int i = 0; i < 26; i++){
            if((s[i] && !t[i]) || (!s[i] && t[i]))  return false;
            if(s[i] != 0)   ++mp[s[i]];
        }
        
        for(int i = 0; i < 26; i++){
            if(t[i] != 0 && mp.find(t[i]) != mp.end()){
                --mp[t[i]];
                if(mp[t[i]] == 0)    mp.erase(t[i]);
            }
        }
        
        return mp.size() == 0;
    }
};