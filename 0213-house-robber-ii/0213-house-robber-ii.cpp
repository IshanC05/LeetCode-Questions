class Solution {
public:
    int dp[101];
    int helper(vector<int>& nums, int i, int n){
        
        if(i >= n)  return 0;
        
        if(dp[i] != -1)     return dp[i];
        
        int steal = nums[i] + helper(nums, i + 2, n);
        int skip = helper(nums, i + 1, n);
        
        return dp[i] = max(steal, skip);
        
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1)  return nums[0];
        
        
        memset(dp, -1, sizeof(dp));
        int includeFirst = helper(nums, 0, n - 1);
        
        memset(dp, -1, sizeof(dp));
        int excludeFirst = helper(nums, 1, n);
        
        return max(includeFirst, excludeFirst);        
    }
};