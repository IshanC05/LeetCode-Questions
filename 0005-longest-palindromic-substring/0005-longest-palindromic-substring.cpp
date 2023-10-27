class Solution {
public:
    int t[1001][1001];
    bool isPalindrome(string &s, int i, int j){
        
        if(i >= j)      return true;
        
        if(t[i][j] != -1)   return t[i][j];
        
        if(s[i] != s[j])    return t[i][j] = false;
        
        return t[i][j] = isPalindrome(s, i + 1, j - 1);
    }
    
    string longestPalindrome(string s) {
        
        int maxSize = 0;
        
        int start = -1;
        
        int n = s.size();
        
        memset(t, -1, sizeof(t));
        
        for(int i = 0; i < n; i++){
            
            for(int j = i; j < n; j++){
                
                if(isPalindrome(s, i, j) && (j - i + 1 > maxSize)){

                    maxSize = j - i + 1;

                    start = i;
                }
                
            }
            
        }
        
        return s.substr(start, maxSize);
    }
};