class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            int target = k - nums[i];
            
            if(mp.find(target) != mp.end()){
                
                ++ans;
                
                --mp[target];
                
                if(mp[target] == 0) mp.erase(target);
                
            }else   ++mp[nums[i]];
            
        }
        
        return ans;
        
    }
};