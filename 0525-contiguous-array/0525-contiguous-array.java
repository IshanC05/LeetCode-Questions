class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        
        int res = 0, sum = 0;
        
        map.put(0, -1);
        
        for(int i = 0; i < n; i++){
            sum = sum + (nums[i] == 1 ? 1 : -1);
            
            if(map.containsKey(sum)){
                res = Math.max(res, i - map.get(sum));
            }else{
                map.put(sum, i);
            }
        }
        
        return res;
    }
}