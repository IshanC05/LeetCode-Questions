class Solution {
    public int maxProductDifference(int[] nums) {
                
        int n = nums.length;
        
        int s1 = Integer.MAX_VALUE, s2 = Integer.MAX_VALUE, t1 = 0, t2 = 0;
        
        for(int i = 0; i < n; i++){
            
            if(nums[i] < s2){
                
                s1 = s2;
                
                s2 = nums[i];
                
            }
            
            else if(nums[i] < s1)  s1 = nums[i];
            
            if(nums[i] > t1){
                
                t2 = t1;
                
                t1 = nums[i];
            }
            
            else if(nums[i] > t2)   t2 = nums[i];
        }
        
        return (t1 * t2) - (s1 * s2);
    }
}