class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        
        int expectedSum = (n * (n + 1)) / 2;
        int currSum = 0;
        
        for(int i : nums)
            currSum = currSum + i;
        
        return expectedSum - currSum;        
    }
}