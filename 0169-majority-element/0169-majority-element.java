class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int majE = nums[0], count = 1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] == majE)     ++count;
            else    --count;
            
            if(count == 0){
                majE = nums[i];
                count = 1;
            }
        }
        
        return majE;
    }
}