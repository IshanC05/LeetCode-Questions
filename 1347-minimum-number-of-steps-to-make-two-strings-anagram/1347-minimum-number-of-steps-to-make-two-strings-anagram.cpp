class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq(26, 0);
        
        for(int i = 0; i < s.length(); i++){
            ++freq[t[i] - 'a'];
            --freq[s[i] - 'a'];
        }
        
        int res = 0;
        
        for(int i : freq)
            res += max(0, i);
        
        return res;
    }
};