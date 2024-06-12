class Solution {
    public void sortColors(int[] nums) {
        int zero = 0, two = 0;
        
        for(int i = 0; i < nums.length; i++){
            zero += (nums[i] == 0 ? 1 : 0);
            two += (nums[i] == 2 ? 1 : 0);
            
            nums[i] = 1;
        }
        
        int i = 0;
        
        while(i < nums.length && zero > 0){
              nums[i++] = 0;
            --zero;
        }
        
        i = nums.length - 1;
        
        while(i >= 0 && two > 0){
            nums[i--] = 2;
            --two;
        }
    }
}