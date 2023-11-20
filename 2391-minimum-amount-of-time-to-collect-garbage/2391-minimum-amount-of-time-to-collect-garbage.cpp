class Solution {
public:    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        unordered_map<char, int>mp;
        
        int res = 0, gsz = garbage.size();
        
        for(int i = 0; i < gsz; i++){
            
            for(char j : garbage[i]){
                
                mp[j] = i;
                
                ++res;
                
            }
            
        }
        
        vector<int>pref(travel);
        
        pref[0] = travel[0];
        
        for(int i = 1; i < travel.size(); i++){         
            
            pref[i] = travel[i] + pref[i - 1];
            
        }
        
        for(auto it : mp){
            
            int lastIdx = it.second - 1;
            
            if(lastIdx >= 0){
                
                res += pref[lastIdx];
                
            }
            
        }
        
           
        return res;
        
    }
};