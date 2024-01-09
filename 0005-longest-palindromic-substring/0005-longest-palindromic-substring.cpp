class Solution {
public:
    int t[1001][1001];
    bool check(string &s, int i, int j){
        if(i >= j)  return true;
        if(s[i] != s[j])    return false;
        
        if(t[i][j] != -1)   return t[i][j];
        
        return t[i][j] = check(s, i + 1, j - 1) == true ? 1 : 0;
    }
    string longestPalindrome(string s) {
        int n = s.length(), maxL = 0;
        
        memset(t, -1, sizeof(t));
        
        string res;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(check(s, i, j) && maxL < (j - i + 1)){
                    maxL = j - i + 1;
                    res = s.substr(i, maxL);
                }
                
            }
        }
        
        return res;
    }
};