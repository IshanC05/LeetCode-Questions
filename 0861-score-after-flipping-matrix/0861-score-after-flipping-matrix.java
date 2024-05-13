class Solution {
    public int matrixScore(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        // rows
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < n; j++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // cols
        for(int j = 1; j < n; j++){
            int count1s = 0;
            for(int i = 0; i < m; i++){
                if(grid[i][j] == 1)     ++count1s;
            }
            
            int count0s = m - count1s;
            
            if(count1s < count0s){
                for(int i = 0; i < m ;i++){
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        int sum = 0;
        
        for(int i = 0; i < m; i++){            
            for(int j = n - 1; j >= 0; j--){
                sum = sum + (grid[i][j] << (n - 1 - j));
            }
        }
        
        return sum;
    }
}