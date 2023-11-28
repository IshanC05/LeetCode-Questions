class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int []res = new int[2];
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        int n = nums.length;
        
        for(int i = 0; i < n; i++){
            
            int k = target - nums[i];
            
            if(mp.containsKey(k)){
                
                res[0] = mp.get(k);
                
                res[1] = i;
                
                break;
                
            }
            
            mp.put(nums[i], i);
            
        }
        
        return res;
        
    }
}