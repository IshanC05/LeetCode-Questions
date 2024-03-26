class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean[] seen = new boolean[n + 1];
        
        for(int num : nums){
            if(num >= 1 && num <= n)    seen[num] = true;
        }
        
        for(int i = 1; i < n + 1; i++){
            if(!seen[i])    return i;
        }
        
        return n + 1;
    }
}