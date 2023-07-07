class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int i = 0, j = 0, n = nums.size();
        
        int ans = 0, flag = 0;
        
        while(j < n){
            
            if(nums[j] == 0)    ++flag;
            
            while(flag > 1){
                
                if(nums[i] == 0)    --flag;
                
                ++i;
                
            }
            
            ans = max(ans, j - i + 1);
            
            ++j;
            
        }
        
        if(ans) --ans;
        
        return ans;
        
    }
};