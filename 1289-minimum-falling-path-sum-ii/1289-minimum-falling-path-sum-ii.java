class Solution {
    int n;
    int[][] t;

    public int solve(int row, int col, int[][] grid) {
        if (row == n - 1) {
            return grid[row][col];
        }

        if (t[row][col] != -1) {
            return t[row][col];
        }

        int ans = Integer.MAX_VALUE;
        for (int nextCol = 0; nextCol < n; nextCol++) {
            if (nextCol != col) {
                ans = Math.min(ans, solve(row + 1, nextCol, grid));
            }
        }

        return t[row][col] = grid[row][col] + ans;
    }

    public int minFallingPathSum(int[][] grid) {
        n = grid.length;
        t = new int[n][n];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        int result = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            result = Math.min(result, solve(0, col, grid));
        }

        return result;
    }
}