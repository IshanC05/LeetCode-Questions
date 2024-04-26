class Solution {
    int n;
    int[][] t;
    
    public int helper(int[][] grid, int i, int j) {
        if (i == n - 1) {
            return grid[i][j];
        }
        
        if(t[i][j] != -1)
            return t[i][j];

        int smallRes = Integer.MAX_VALUE;

        for (int y = 0; y < n; y++) {
            if (y != j) {
                smallRes = Math.min(smallRes, helper(grid, i + 1, y));
            }
        }

        return t[i][j] = smallRes + grid[i][j];
    }
    
    public int minFallingPathSum(int[][] grid) {
        n = grid.length;
        int res = Integer.MAX_VALUE;
        
        t = new int[n + 1][n + 1];
        
        for(int i = 0; i < n; i++)
            Arrays.fill(t[i], -1);
        
        for(int j = 0; j < n; j++){
            res = Math.min(res, helper(grid, 0, j));
        }
        
        return res;
    }
}