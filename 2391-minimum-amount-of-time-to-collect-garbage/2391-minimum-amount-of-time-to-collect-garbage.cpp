class Solution {
public:
    int helper(vector<string>& garbage, vector<int>& travel, char gtype, int lastIdx){
        
        int ans = 0, k = lastIdx - 1;
        
        for(int i = lastIdx; i >= 0; i--){
            
            int prevAns = ans;
            
            for(char j : garbage[i]){
                
                if(j == gtype)  ++ans;
                
            }
            
            if(k >= 0)   ans += travel[k--];
            
        }
        
        return ans;
        
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        unordered_map<char, int>mp;
        
        int res = 0, gsz = garbage.size(), tsz = gsz - 1;
        
        mp.insert({'P', 0});
        
        mp.insert({'G', 0});
        
        mp.insert({'M', 0});
        
        for(int i = 0; i < gsz; i++){
            
            for(char j : garbage[i]){
                
                mp[j] = i;
                
            }
            
        }
        
        for(auto it : mp){
            
            int smallAns = helper(garbage, travel, it.first, it.second);
            
            res += smallAns;
            
        }
        
        return res;
        
    }
};