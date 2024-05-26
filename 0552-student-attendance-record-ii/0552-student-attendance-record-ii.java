class Solution {
    private int[][][] memo;
    
    private static final int MOD = 1000000007;

    private int helper(int idx, int n, int absCount, int lateCount){
        if(absCount >= 2 || lateCount >= 3)
            return 0;
        
        if(idx == n)
            return ((absCount < 2 && absCount < 3) ? 1 : 0);
        
        if(memo[idx][absCount][lateCount] != -1)
            return memo[idx][absCount][lateCount];
        
        int res = 0;
        
        res = (res + helper(idx + 1, n, absCount, 0)) % MOD;
        res = (res + helper(idx + 1, n, absCount + 1, 0)) % MOD;
        res = (res + helper(idx + 1, n, absCount, lateCount + 1)) % MOD;
        
        return memo[idx][absCount][lateCount] = res;
    }
    
    public int checkRecord(int n) {
        memo = new int[n + 1][2][3];
        
        for(int[][] array2D : memo){
            for(int[] array1D : array2D){
                Arrays.fill(array1D, -1);
            }
        }
        
        return helper(0, n, 0, 0);
    }
}