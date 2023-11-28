class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        int n = nums.length;
        
        for(int i = 0; i < n; i++){
            
            int k = target - nums[i];
            
            if(mp.containsKey(k))   return new int[] {mp.get(k), i};
            
            mp.put(nums[i], i);
            
        }
        
        return new int[] {};
        
    }
}