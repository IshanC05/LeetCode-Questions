class Solution {
    int rows, cols;
    int[][][] t;

    public int cherryPickup(int[][] grid) {
        rows = grid.length;
        cols = grid[0].length;
        t = new int[rows][cols][cols];
        for (int[][] layer : t) {
            for (int[] row : layer) {
                Arrays.fill(row, -1);
            }
        }
        return helper(grid, 0, 0, cols - 1);
    }

    public int helper(int[][] grid, int r, int c0, int c1) {
        if (c0 < 0 || c0 >= cols || c1 < 0 || c1 >= cols || r == rows) return 0;

        if (t[r][c0][c1] != -1) return t[r][c0][c1];

        int res = grid[r][c0] + grid[r][c1];

        int smallRes = 0;

        for (int i = c0 - 1; i <= c0 + 1; i++) {
            for (int j = c1 - 1; j <= c1 + 1; j++) {
                if (i < j) {
                    smallRes = Math.max(smallRes, helper(grid, r + 1, i, j));
                }
            }
        }

        res += smallRes;
        return t[r][c0][c1] = res;
    }
}