class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int,vector<int>>mp;
        
        vector<vector<int>>ans;
        
        for(int i = 0; i < groupSizes.size(); i++){
            
            int gs = groupSizes[i];
            
            if(mp.find(gs) == mp.end()){
                
                mp[gs].push_back(i);
                
            }else{
                
                if(mp[gs].size() < gs){
                    
                    mp[gs].push_back(i);
                
                }else{
                    
                    ans.push_back(mp[gs]);
                    
                    mp[gs].clear();
                    
                    mp[gs].push_back(i);
                
                }
                
            }
            
            if(mp[gs].size() == gs){
                
                ans.push_back(mp[gs]);
                
                mp[gs].clear();
                
            }
            
        }
        
        return ans;
        
    }
};