class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int>mp;
        for(char x : s){
            ++mp[x];
        }
        int ans = INT_MAX;
        int i = 0, j = 0, n = s.size();
        int k = n / 4;
        while(j < n){
            --mp[s[j]];
            while(i < n and mp['Q'] <=k and mp['R'] <=k and mp['E'] <=k and mp['W'] <= k){
                ++mp[s[i]];
                ans = min(ans, j - i + 1);
                ++i;
            }
            ++j;
        }
        return ans;
    }
};