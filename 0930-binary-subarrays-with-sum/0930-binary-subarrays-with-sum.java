class Solution {
    public int getArrays(int[] nums, int goal){
        int i = 0, j = 0, n = nums.length;
        int sum = 0, res = 0;
        
        while(j < n){
            sum += nums[j];
            
            while(sum > goal && i <= j){
                sum -= nums[i++];
            }
            
            res += (j - i + 1);
            ++j;
        }
        
        return res;
    }
    public int numSubarraysWithSum(int[] nums, int goal) {
        return getArrays(nums, goal) - getArrays(nums, goal - 1);
    }
}