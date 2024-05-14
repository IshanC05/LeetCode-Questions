class Solution {
public:
    
    int r, c;
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, +1};
    
    int helper(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j] == 0)
            return 0;
        
        int res = 0;
        int prev = grid[i][j];
        grid[i][j] = 0;
        
        for(int k = 0; k < 4; k++){
            
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && x < r && y >= 0 && y < c)
                res = max(res, prev + helper(grid, x, y));
        }
        
        grid[i][j] = prev;
        return res;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int res = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                res = max(res, helper(grid, i, j));
            }
        }
        
        return res;
    }
};