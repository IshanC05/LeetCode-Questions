class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxs = nums[0], cmax = nums[0];
        int mins = nums[0], cmin = nums[0];
        int totalSum = nums[0];
        
        for(int i = 1; i < n; i++){
            cmax = max(cmax + nums[i], nums[i]);
            maxs = max(maxs, cmax);
            
            cmin = min(cmin + nums[i], nums[i]);
            mins = min(mins, cmin);
            
            totalSum += nums[i];
        }
        
        int circularSum = totalSum - mins;
        
        if(maxs > 0)    return max(maxs, circularSum);
        
        return maxs;
    }
};