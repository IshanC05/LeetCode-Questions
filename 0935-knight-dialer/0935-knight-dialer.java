public class Solution {

    private static final int[][] ways = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    private static final int MOD = 1000000007;
    private static long[][] memo;

    public int knightDialer(int n) {
        memo = new long[n + 1][10];
        initializeMemo();

        long result = 0;

        for (int i = 0; i < 10; i++) {
            result = (result + helper(n - 1, i)) % MOD;
        }

        return (int) result;
    }

    private void initializeMemo() {
        for (long[] row : memo) {
            Arrays.fill(row, -1);
        }
    }

    private long helper(int remainingSteps, int currentDigit) {
        if (remainingSteps == 0) {
            return 1;
        }

        if (memo[remainingSteps][currentDigit] != -1) {
            return memo[remainingSteps][currentDigit];
        }

        long waysCount = 0;

        for (int nextDigit : ways[currentDigit]) {
            waysCount = (waysCount + helper(remainingSteps - 1, nextDigit)) % MOD;
        }

        return memo[remainingSteps][currentDigit] = waysCount;
    }
}
