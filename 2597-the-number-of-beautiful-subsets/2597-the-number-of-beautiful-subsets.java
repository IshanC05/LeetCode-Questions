class Solution {
    private int res;
    
    private void helper(int[] nums, int i, int k, Set<Integer> set){
        if(i == nums.length){
            if(set.size() > 0)     ++res;
            return;
        }
        
        helper(nums, i + 1, k, set);
        
        if(!set.contains(nums[i] - k) && !set.contains(nums[i] + k)){
            set.add(nums[i]);
            helper(nums, i + 1, k, set);
            set.remove(nums[i]);
        }
        
    }
    
    public int beautifulSubsets(int[] nums, int k) {
        res = 0;
        Set<Integer> set = new HashSet<>();
        Arrays.sort(nums);
        
        helper(nums, 0, k, set);
        
        return res;
    }
}