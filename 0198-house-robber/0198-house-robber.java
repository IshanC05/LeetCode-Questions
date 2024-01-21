class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        
        if(n == 1)  return nums[0];
        
        int prev0 = nums[0];
        int prev1 = Math.max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            int cur = Math.max(prev1, prev0 + nums[i]);
            prev0 = prev1;
            prev1 = cur;
        }
        
        return prev1;
    }
}