//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, +1, +1, +1};
    
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        
        grid[i][j] = '0';
        
        for(int k = 0; k < 8; k++){
            
            int x = i + dx[k];
            int y = j + dy[k];
            
            if((x >= 0 && y >= 0 && x < n && y < m) && grid[x][y] == '1'){
                
                dfs(grid, x, y, n, m);
                
            }
        }
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        
        queue<pair<int, int>>q;
        q.push({i, j});
        
        grid[i][j] = '0';
        
        while(!q.empty()){
            
            int X = q.front().first;
            int Y = q.front().second;
            q.pop();
            
            for(int k = 0; k < 8; k++){
                
                int x = X + dx[k];
                int y = Y + dy[k];
                
                if((x >= 0 && x < n && y >= 0 && y < m) && grid[x][y] == '1'){
                    
                    grid[x][y] = '0';
                    
                    q.push({x, y});
                    
                }
                
            }
            
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), res = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == '1'){
                    
                    ++res;
                    
                    // dfs(grid, i, j, n, m);
                    bfs(grid, i, j, n, m);
                    
                }
                
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends