class Solution {
    int[][] t;

    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        t = new int[n][n];

        for (int[] row : t) {
            Arrays.fill(row, (int) 1e8);
        }

        int res = Integer.MAX_VALUE;

        for (int j = 0; j < n; j++) {
            res = Math.min(res, dfs(matrix, 0, j, n));
        }

        return res;
    }

    private int dfs(int[][] mat, int i, int j, int n) {
        if (i == n - 1) return t[i][j] = mat[i][j];

        if (t[i][j] != 1e8) return t[i][j];

        int sum = Integer.MAX_VALUE;

        int[] dx = {1, 1, 1};
        int[] dy = {-1, 0, 1};

        for (int k = 0; k < 3; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < n) {
                sum = Math.min(sum, mat[i][j] + dfs(mat, x, y, n));
            }
        }

        return t[i][j] = sum;
    }
}