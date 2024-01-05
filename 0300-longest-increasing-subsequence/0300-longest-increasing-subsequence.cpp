class Solution {
public:
    int t[2505][2505];
    int helper(vector<int>& nums, int i, int prev_i){
        if(i >= nums.size())    return 0;
        
        if(t[i][prev_i + 1] != -1)  return t[i][prev_i + 1];
        
        int pick = 0, notPick = 0;
        
        if(prev_i == -1 || nums[i] > nums[prev_i]){
            pick = 1 + helper(nums, i + 1, i);
        }
        
        notPick = helper(nums, i + 1, prev_i);
        
        return t[i][prev_i + 1] = max(pick, notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return helper(nums, 0, -1);
    }
};