class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>lastIdx(26, -1);
        
        int res = -1;
        
        for(int i = 0; i < s.size(); i++){
            
            if(lastIdx[s[i] - 'a'] == -1)   lastIdx[s[i] - 'a'] = i;
            
            else    res = max(res, i - lastIdx[s[i] - 'a'] - 1);
        }
        
        return res;
    }
};