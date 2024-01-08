class Solution {
public:
    int t[1001][1001];
    bool check(string &s, int l, int r){
        if(l >= r)   return true;
        if(s[l] != s[r])    return false;
        
        if(t[l][r] != -1)   return t[l][r];
        
        return t[l][r] = check(s, l + 1, r - 1);
    }
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        
        memset(t, -1, sizeof(t));
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(check(s, i, j))    ++res;
            }
        }
        
        return res;
    }
};