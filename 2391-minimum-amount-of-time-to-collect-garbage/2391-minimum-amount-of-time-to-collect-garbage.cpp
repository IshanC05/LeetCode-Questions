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
        
        for(int i = 1; i < travel.size(); i++){         
            
            travel[i] = travel[i] + travel[i - 1];
            
        }
        
        for(auto it : mp){
                
            res += it.second - 1 >= 0 ? travel[it.second - 1] : 0;
            
        }
        
           
        return res;
    }
};