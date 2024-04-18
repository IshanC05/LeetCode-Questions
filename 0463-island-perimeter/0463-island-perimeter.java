class Solution {
    int res;
    
    int[] dx = {-1, 0, +1, 0};
    int[] dy = {0, -1, 0, +1};
    
    public boolean check(int x, int y, int r, int c){
        return (x >= 0 && x < r && y >= 0 && y < c);
    }
    
    public void dfs(int[][] grid, int i, int j, int r, int c){
        if(!check(i, j, r, c) || grid[i][j] == 0) {
            ++res;
            return;
        }
        
        if (grid[i][j] == -1)
            return;
        
        grid[i][j] = -1;
        
        for(int k = 0; k < 4; k++){

            int x = i + dx[k];
            int y = j + dy[k];
            
            dfs(grid, x, y, r, c);
        }
    }
    
    public int islandPerimeter(int[][] grid) {
        res = 0;
        int rows = grid.length;
        int cols = grid[0].length;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1)     
                    dfs(grid, i, j, rows, cols);
            }
        }
        
        return res;
    }
}
