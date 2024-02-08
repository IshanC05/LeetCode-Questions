class Solution {
    public int helper(List<Integer> coins, int n, int sum, int[][] t) {
        if (sum == 0) return 0;
        if (n == 0) return Integer.MAX_VALUE - 1;

        if (t[n][sum] != 0) return t[n][sum];

        if (coins.get(n - 1) <= sum) {
            int take = 1 + helper(coins, n, sum - coins.get(n - 1), t);
            int skip = helper(coins, n - 1, sum, t);

            return t[n][sum] = Math.min(take, skip);
        }

        return t[n][sum] = helper(coins, n - 1, sum, t);
    }

    public int numSquares(int n) {
        List<Integer> squares = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            squares.add(i * i);
        }

        int[][] t = new int[squares.size() + 1][n + 1];
        return helper(squares, squares.size(), n, t);
    }
}