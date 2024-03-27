class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int prod = 1;
        int i = 0, j = 0, n = nums.length;
        int res = 0;
        
        while(j < n){
            prod = prod * nums[j];
            
            while(i < j && prod >= k){
                prod = prod / nums[i];
                ++i;
            }
            
            if(prod < k)    
                res += j - i + 1;
            
            ++j;
        }
        
        return res;
    }
}