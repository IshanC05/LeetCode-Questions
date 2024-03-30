class Solution {
    public int helper(int[] nums, int k){
        int n = nums.length;
        int i = 0, j = 0;
        int res = 0;
        
        Map<Integer, Integer>map = new HashMap<>();
        
        while(j < n){
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            
            while(map.size() > k){
                map.put(nums[i], map.get(nums[i]) - 1);
                
                if(map.get(nums[i]) == 0)   
                    map.remove(nums[i]);
                
                ++i;
            }
            
            res += (j - i + 1);
            ++j;
        }
        
        return res;        
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        int withK = helper(nums, k);
        int withOutK = helper(nums, k - 1);
        
        return withK - withOutK;
    }
}