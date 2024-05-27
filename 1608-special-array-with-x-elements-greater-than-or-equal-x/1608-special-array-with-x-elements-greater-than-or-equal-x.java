class Solution {
    public int specialArray(int[] nums) {
        int[] count = new int[1001];
        int maxVal = -1;
        
        for (int num : nums) {
            count[num]++;
            maxVal = Math.max(maxVal, num);
        }

        int numCount = 0;
        for (int x = maxVal; x >= 0; x--) {
            numCount += count[x];
            if (numCount == x) {
                return x;
            }
        }

        return -1;
    }
}