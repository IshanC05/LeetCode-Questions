class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>>result(m, vector<int>(n, INT_MAX));
              
        queue<pair<int, int>>q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 0){
                    q.push({i, j});
                    result[i][j] = 0;
                }
                
            }
        }
        
        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = {0, -1, 0, +1};
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            
            int i = curr.first;
            int j = curr.second;
            
            int d = result[i][j];
            
            for(int k = 0; k < 4; k++){
                
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(x >= 0 && x < m && y >= 0 && y < n && result[x][y] > 1 + d){
                    result[x][y] = 1 + d;
                    q.push({x, y});
                }
                
            }
        }
        
        return result;
        
    }
};