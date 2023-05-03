class Solution {
public:
    int firstUniqChar(string s) {
        int idx = 0, n = s.size();
        unordered_map<char,int>mp;
        for(int i = 0; i < n; i++){
            ++mp[s[i]];
            if(mp[s[idx]] > 1){
                while(idx < n and mp[s[idx]] > 1){
                    ++idx;
                }
            }
            if(idx == n){
                return -1;
            }
        }
        return idx;
    }
};