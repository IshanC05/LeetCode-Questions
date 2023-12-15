class Solution {
public:
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, +1};
    
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        
        grid[i][j] = '0';
        
        for(int k = 0; k < 4; k++){
            
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1'){
                
                dfs(grid, x, y, m, n);
                
            }   
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        int res = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j] == '1'){
                    ++res;
                    dfs(grid, i, j, m, n);
                }
                
            }
        }
        
        return res;        
    }
};