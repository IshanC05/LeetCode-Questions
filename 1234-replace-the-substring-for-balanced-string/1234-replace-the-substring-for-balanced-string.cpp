class Solution {
public:
    int balancedString(string s) {
        
        unordered_map<char,int>mp;
        
        int n = s.size(), k = n / 4, j = 0, i = 0, ans = n;
        
        for(char i : s)     ++mp[i];
        
        while(j < n){
            
            --mp[s[j]];
            
            while(i < n && mp['Q'] <= k && mp['W'] <= k && mp['E'] <= k && mp['R'] <= k){
                
                ++mp[s[i]];
                
                ans = min(ans, j - i + 1);
                
                ++i;
                
            }
            
            ++j;
            
        }
        
        return ans;
        
    }
};