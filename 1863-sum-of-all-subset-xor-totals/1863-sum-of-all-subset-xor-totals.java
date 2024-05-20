class Solution {
    int res;
    
    public void helper(int[] nums, int i, int smallRes){
        if(i >= nums.length){
            res += smallRes;
            return;
        }
        
        helper(nums, i + 1, smallRes);
        helper(nums, i + 1, smallRes ^ nums[i]);
    }
    
    public int subsetXORSum(int[] nums) {
        res = 0;
        helper(nums, 0, 0);
        return res;
    }
}