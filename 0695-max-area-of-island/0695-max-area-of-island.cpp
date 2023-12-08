class Solution {
public:
    set<pair<int,int>>vis;
    
    bool isValid(vector<vector<int>>& grid, int x, int y, int r, int c){
    
        if(x < 0 || y < 0 || x >= r || y >= c || grid[x][y] == 0)   return false;
    
        if(vis.find({x, y}) != vis.end())   return false;
        
        return true;        
    }
    
    // left top right bottom
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, +1};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        
        int smallAns = 1;
        
        for(int k = 0; k < 4; k++){
            
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(isValid(grid, x, y, m, n)){
                
                vis.insert({x, y});
                
                smallAns += dfs(grid, x, y, m, n);
                
            }
            
        }
        
        return smallAns;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vis.clear();
        
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(isValid(grid, i, j, m, n)){
                    
                    vis.insert({i, j});
                    
                    int smallAns = dfs(grid, i, j, m, n);
                    
                    res = max(res, smallAns);
                    
                }
                
            }
        }
        
        return res;        
    }
};