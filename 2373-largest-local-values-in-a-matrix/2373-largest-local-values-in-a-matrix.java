class Solution {
    private int helper(int[][] grid, int i, int j){
        int elem = 0;
        
        for(int x = i; x < i + 3; x++){
            for(int y = j; y < j + 3; y++){
                elem = Math.max(elem, grid[x][y]);
            }
        }
        
        return elem;
    }
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] res = new int[n - 2][n - 2];
        
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < n - 2; j++){
                
                res[i][j] = helper(grid, i, j);
                
            }
        }
        
        return res;
    }
}