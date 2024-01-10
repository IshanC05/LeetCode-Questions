class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>>q;
        
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(board[i][j] == 'O' && (i == 0 || i == m - 1 || j == 0 || j == n - 1)){
                    q.push({i, j});
                    vis[i][j] = 1;                
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
            
            for(int k = 0; k < 4; k++){
                
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !vis[x][y]){
                    q.push({x, y});
                    vis[x][y] = 1;
                }
                
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(board[i][j] == 'O' && !vis[i][j])    
                    board[i][j] = 'X';
                
            }
        }
        
        return;
    }
};