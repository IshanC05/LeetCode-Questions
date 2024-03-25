class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Set<Integer>set = new HashSet<>();
        
        for(int i : nums){
            int idx = Math.abs(i);
            
            if(nums[idx - 1] < 0)   set.add(idx);
            
            nums[idx - 1] = -nums[idx - 1];
        }
        
        return new ArrayList<>(set);
    }
}