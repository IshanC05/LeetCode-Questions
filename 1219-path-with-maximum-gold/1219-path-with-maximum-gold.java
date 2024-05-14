class Solution {
    
    int r, c;
    int[] dx = {-1, 0, +1, 0};
    int[] dy = {0, -1, 0, +1};
    
    public int helper(int[][] grid, int i, int j){
        if(grid[i][j] == 0)
            return 0;
        
        int res = 0;
        int prev = grid[i][j];
        grid[i][j] = 0;
        
        for(int k = 0; k < 4; k++){
            
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && x < r && y >= 0 && y < c)
                res = Math.max(res, prev + helper(grid, x, y));
        }
        
        grid[i][j] = prev;
        return res;
    }
    
    public int getMaximumGold(int[][] grid) {
        r = grid.length;
        c = grid[0].length;
        int res = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                res = Math.max(res, helper(grid, i, j));
            }
        }
        
        return res;
    }
}