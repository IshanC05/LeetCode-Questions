class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        int ans = INT_MAX;
        set<int>val;
        for(int i=x;i<nums.size();++i){
            val.insert(nums[i-x]);
            auto it = val.lower_bound(nums[i]);
            
            if(it == val.end()){
                it--;
            }
            
            int close_val = *it;
            int dif = abs(nums[i]-close_val);
            ans = min(ans,dif);
            
            if(it == val.begin())continue;
            
            it--;
            close_val = *it;
            dif = abs(nums[i]-close_val);
            ans = min(ans,dif);
            
        }
        return ans;
        
    }
};