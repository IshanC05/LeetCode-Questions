class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        
        vector<vector<bool>>t(n + 1, vector<bool>(n + 1, false));
        
        for(int gap = 0; gap < n; gap++){
            for(int l = 0, r = gap; r < n; l++, r++){
                
                if(gap == 0){
                    t[l][r] = true;
                }else if(gap == 1){
                    t[l][r] = s[l] == s[r];
                }else{
                    t[l][r] = (t[l + 1][r - 1] == true && s[l] == s[r]);
                }
                
                if(t[l][r])     ++res;
                
            }
        }
        
        return res;
    }
};