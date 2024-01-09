class Solution {
public:
    unordered_map<string, bool>memo;
    bool helper(string s, unordered_set<string>&dict){
        if(s.size() == 0)   return true;
        if(dict.find(s) != dict.end())  return true;
        
        if(memo.find(s) != memo.end())  return memo[s];
        
        string curr;
        
        for(int i = 0; i < s.size() - 1; i++){
            curr.push_back(s[i]);
            if(dict.find(curr) != dict.end())   
                if(helper(s.substr(i + 1), dict))    return memo[s] = true;
        }
        
        return memo[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        memo.clear();
        return helper(s, dict);
    }
};