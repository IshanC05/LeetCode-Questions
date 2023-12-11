//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
    
        // Mark and enqueue 1s on the border
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
    
        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = {0, -1, 0, +1};
    
        // Perform BFS to mark connected components
        while (!q.empty()) {
            int X = q.front().first;
            int Y = q.front().second;
            q.pop();
    
            for (int k = 0; k < 4; k++) {
                int x = X + dx[k];
                int y = Y + dy[k];
    
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                    grid[x][y] = 0;
                    q.push({x, y});
                }
            }
        }
    
        int res = 0;
    
        // Count remaining 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = grid[i][j] == 1 ? ++res : res;
            }
        }
    
        return res;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends