class Solution {
    public int findMaxK(int[] nums) {
        int res = -1;
        Set<Integer>seen = new HashSet<>();
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] < 0 && seen.contains(-nums[i])){
                res = Math.max(res, -nums[i]);
            }else if(nums[i] > 0 && seen.contains(-nums[i])){
                res = Math.max(res, nums[i]);
            }
            
            seen.add(nums[i]);
        }
        
        return res;
    }
}