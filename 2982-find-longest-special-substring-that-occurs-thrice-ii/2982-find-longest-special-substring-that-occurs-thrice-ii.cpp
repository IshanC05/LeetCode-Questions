class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        
        map<char, vector<int>>mp;
        
        for(int i = 0; i < n;){
            int j = i;
            int len = 0;
            
            while(j < n && s[i] == s[j]){
                ++len;
                ++j;
            }
            
            mp[s[i]].push_back(len);
            
            i = j;
        }
        
        int res = -1;
        
        for(auto it : mp){
            
            int l = 0, m = 0, h = 0;
            
            for(auto x : it.second){
                
                if(x > h){
                    l = m;
                    m = h;
                    h = x;
                }else if(x > m){
                    l = m;
                    m = x;
                }else if(x > l){
                    l = x;
                }
                
            }
            
            if(h == m && h > l) --m;
            if(h + m + l >= 3)  res = max({res, h - 2, m});
            
        }
        
        return res == 0 ? -1 : res;
        
    }
};