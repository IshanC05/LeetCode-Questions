class Solution {
public:
    int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, +1, +1, +1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), level = 0;
        
        if(n == 0 || grid[0][0] != 0)   return -1;
        
        queue<pair<int, int>>q;
        grid[0][0] = 1;
        q.push({0, 0});
        
        while(!q.empty()){
            
            int N = q.size();
            
            while(N--){
                
                auto curr = q.front();
                q.pop();
                
                int X = curr.first;
                int Y = curr.second;

                if(X == n - 1 && Y == n - 1)    
                    return level + 1;

                for(int k = 0; k < 8; k++){

                    int x = X + dx[k];
                    int y = Y + dy[k];

                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0){
                        grid[x][y] = 1;
                        q.push({x, y});                    
                    }
                }
            
            }
            
            ++level;
        }
        
        return -1;
    }
};