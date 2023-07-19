class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(k == s.size())   return true;
        
        else if(k > s.size())   return false;
        
        int odd = 0;
        
        vector<int>freq(26, 0);
        
        for(char i : s) ++freq[i - 'a'];
        
        for(int i : freq)   if(i & 1)   ++odd;
        
        return odd <= k;
        
    }
};