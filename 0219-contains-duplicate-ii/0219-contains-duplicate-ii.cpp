class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     
        unordered_map<int,int>mp;
        
        bool flag = false;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(mp.find(nums[i]) == mp.end()){
                
                
            }else{
                        
                if(abs(mp[nums[i]] - i) <= k && mp[nums[i]] != i)   flag = true;
                
            }
            
            mp[nums[i]] = i;
            
        }
        
        return flag;
        
    }
};