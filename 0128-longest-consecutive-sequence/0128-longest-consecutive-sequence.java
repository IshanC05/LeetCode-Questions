class Solution {
    public int longestConsecutive(int[] nums) {
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++){
            
            if(mp.containsKey(nums[i]))     mp.put(nums[i], mp.get(nums[i]) + 1);
            
            else    mp.put(nums[i], 1);            
        }
        
        int res = 0;
        
        Set<Integer> checked = new HashSet<>();
        
        for(Integer key : mp.keySet()){
            
            if(mp.containsKey(key - 1) || checked.contains(key))     continue;
            
            int smallAns = 0, start = key;
            
            while(mp.containsKey(start)){
                
                checked.add(start);
                
                ++smallAns;
                
                ++start;
                
            }
            
            res = Math.max(res, smallAns);
            
        }
        
        return res;
        
    }
}