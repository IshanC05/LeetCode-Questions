class Solution {
    private List<List<Integer>> res;
    
    private void helper(int[] nums, int idx, List<Integer>smallRes){
        if(idx == nums.length){
            res.add(new ArrayList<>(smallRes));
            return;
        }
        
        smallRes.add(nums[idx]);
        helper(nums, idx + 1, smallRes);
        smallRes.remove(smallRes.size() - 1);
        
        helper(nums, idx + 1, smallRes);
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        List<Integer>smallRes = new ArrayList<>();
        
        helper(nums, 0, smallRes);
        
        return res;
    }
}