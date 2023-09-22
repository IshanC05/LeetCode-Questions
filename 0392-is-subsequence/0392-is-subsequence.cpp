class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int m = t.size(), n = s.size(), j = 0;
        
        for(int i = 0; i < m; i++){
            if(j < n && s[j] == t[i])   ++j;            
        }
        
        return j == n;        
    }
};