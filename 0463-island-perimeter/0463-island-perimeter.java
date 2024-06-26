class Solution {
    public int islandPerimeter(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        
        int res = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                
                if(grid[i][j] == 1){
            
                    res += 4;
                    
                    if(i > 0 && grid[i - 1][j] == 1)    
                        --res;
                    
                    if(i + 1 < r && grid[i + 1][j] == 1)    
                        --res;
                    
                    if(j > 0 && grid[i][j - 1] == 1)
                        --res;
                    
                    if(j + 1 < c && grid[i][j + 1] == 1)    
                        --res;
                }
            }
        }
        
        return res;
    }
}