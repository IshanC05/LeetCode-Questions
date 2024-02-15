class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        
        long prefixSum[] = new long[n], res = -1;

        prefixSum[0] = nums[0];
        
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        
        for (int i = 2; i < n; ++i) {
            if (nums[i] < prefixSum[i - 1]) 
                res = Math.max(res, prefixSum[i]);
        }

        return res;
    }
}