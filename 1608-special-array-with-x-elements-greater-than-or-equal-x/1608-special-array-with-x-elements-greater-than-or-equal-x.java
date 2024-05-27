class Solution {
    public int specialArray(int[] nums) {
        int[] count = new int[1001];
        
        for (int num : nums) {
            count[num]++;
        }

        int numCount = 0;
        for (int x = 1000; x >= 0; x--) {
            numCount += count[x];
            if (numCount == x) {
                return x;
            }
        }

        return -1;
    }
}