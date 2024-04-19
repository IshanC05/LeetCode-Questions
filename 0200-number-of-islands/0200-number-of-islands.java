class Solution {
    
    int[] dx = {-1, 0, +1, 0};
    int[] dy = {0, -1, 0, +1};
    
    public void dfs(char[][] grid, int i, int j, int r, int c){
        grid[i][j] = '0';
        
        for(int k = 0; k < 4; k++){
            
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == '1')
                dfs(grid, x, y, r, c);
            
        }
    }
    
    public int numIslands(char[][] grid) {
        int res = 0;
        int r = grid.length;
        int c = grid[0].length;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    ++res;
                    dfs(grid, i, j, r, c);
                }
            }
        }
        
        return res;
    }
}