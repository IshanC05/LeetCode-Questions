class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>> &grid, int i, int j){
        
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)   return;
        
        grid[i][j] = 0;
        
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        
    }
    int numEnclaves(vector<vector<int>> &grid) {
        // Code here
        n = grid.size(), m = grid[0].size();
        
        // cover boundary columns
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1)
                dfs(grid, i, 0);
                
            if(grid[i][m - 1] == 1)
                dfs(grid, i, m - 1);
        }
        
        // cover boundary rows
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1)
                dfs(grid, 0, j);
                
            if(grid[n - 1][j] == 1)
                dfs(grid, n - 1, j);
        }
        
        // count 1s
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)     ++count;
            }
        }
        
        return count;
    }
};