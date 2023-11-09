class Solution {
public:
    int countHomogenous(string s) {
        
        long long int res = 0;
        
        int n = s.size();
        
        int i = 0, j = 0, mod = 1e9+7;
        
        while(i < n){
            
            j = i;
            
            while(j < n && s[j] == s[i]){
                res += (j - i + 1);
                res = res % mod;
                ++j;
            }
            
            i = j;
            
        }
        
        return res;        
    }
};