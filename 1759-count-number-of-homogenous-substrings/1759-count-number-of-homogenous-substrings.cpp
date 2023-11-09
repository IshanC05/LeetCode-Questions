class Solution {
public:
    int countHomogenous(string s) {
        
        long long int res = 0;
        
        int n = s.size();
        
        int mod = 1e9+7, curr = 0;
        
        for(int i = 0; i < n; i++){
            
            if(i == 0 || s[i] == s[i - 1])    ++curr;
            
            else    curr = 1;
            
            res = (res + curr) % mod;
            
        }
        
        return res;        
    }
};