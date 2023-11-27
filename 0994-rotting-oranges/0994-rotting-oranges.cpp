class Solution {
public:
    bool isValid(vector<vector<int>> &grid, int x, int y, int r, int c){
    
        if((x < 0 || y < 0) || (x >= r || y >= c))  return false;
        
        else if(grid[x][y] == 2 || grid[x][y] == 0)     return false;
        
        return true;        
    }
    
    int bfs(vector<vector<int>> grid, vector<pair<int,int>>&start, int r, int c){
        
        queue<pair<int,pair<int, int>>>q;
        
        for(auto it : start){
            
            int i = it.first;
            int j = it.second;
            
            q.push({0,{i, j}});
            
        }
        
        vector<int>dx = {0, -1, +1, 0};
        vector<int>dy = {-1, 0, 0, +1};
        
        
        int res = 0;
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            
            int time = f.first;
            
            res = max(res, time);
            int x = f.second.first;
            int y = f.second.second;
            
            
            for(int k = 0; k < 4; k++){
                
                int a = x + dx[k];
                int b = y + dy[k];
                
                if(isValid(grid, a, b, r, c)){
                    grid[a][b] = 2;
                    q.push({time + 1, {a, b}});
                }
                
            }                  
            
        }
        
        
        for(int m = 0; m < r; m++){
            for(int n = 0; n < c; n++){            
                if(grid[m][n] == 1)     return -1;
            }
        }
        
        return res;        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size();
        
        bool isOrange = false;
        
        // if no orange is Present
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] != 0){
                    isOrange = true;
                    break;
                }
            }
        }
        
        if(!isOrange)   return 0;
        
        // start points for bfs        
        vector<pair<int,int>>start;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 2){
                    start.push_back({i, j});
                }
            }
        }
        
        int res = bfs(grid, start, r, c);
        
        return (res == INT_MAX) ? -1 : res;
        
    }
};