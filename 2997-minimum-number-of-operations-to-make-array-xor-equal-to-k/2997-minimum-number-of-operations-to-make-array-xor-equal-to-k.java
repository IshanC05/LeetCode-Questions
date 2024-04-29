class Solution {
    public int minOperations(int[] nums, int k) {
        int xorr = 0;
        
        for(int num : nums) 
            xorr ^= num;
        
        xorr ^= k;

        int ans = 0;
        
        while(xorr > 0) {
            ans += (xorr & 1);
            xorr = (xorr >> 1);
        }

        return ans;
    }
}