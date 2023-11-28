class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int n = nums.length;
        
        int []res = {-1, -1};
        
        for(int i = 0; i < n - 1; i++){
            
            for(int j = i + 1; j < n; j++){
                
                if(nums[i] + nums[j] == target){
                    
                    res[0] = i;
                    
                    res[1] = j;
                    
                    return res;
                    
                }    
                
            }
            
        }
        
        return res;
        
    }
}