class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer>res = new ArrayList<>();
        
        for(int i : nums){
            int idx = Math.abs(i) - 1;
            
            if(nums[idx] < 0)   
                res.add(idx + 1);
            
            nums[idx] = -nums[idx];
        }
        
        return res;
    }
}