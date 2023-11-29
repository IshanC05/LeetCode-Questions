class Solution {
    public int check(Map<Integer, Integer> mp, int val){
        return mp.containsKey(val) ? mp.get(val) : 0;
    }
    
    public int countKDifference(int[] nums, int k) {    
        int res = 0;
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++){
            
            int t1 = nums[i] + k;
            
            int t2 = nums[i] - k;
            
            res += check(mp, t1) + check(mp, t2);
            
            if(mp.containsKey(nums[i]))      mp.put(nums[i], mp.get(nums[i]) + 1);
            
            else    mp.put(nums[i], 1);
        }
        
        return res;
        
    }
}