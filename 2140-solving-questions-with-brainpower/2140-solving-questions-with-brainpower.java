class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] t = new long[n + 1]; 
        
        for (int i = n - 1; i >= 0; i--) {
            long solve = questions[i][0] + (i + 1 + questions[i][1] <= n ? t[i + 1 + questions[i][1]] : 0);
            long skip = i + 1 < n ? t[i + 1] : 0;
            t[i] = Math.max(solve, skip);
        }
        
        return t[0];
    }
}