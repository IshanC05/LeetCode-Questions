class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int x, int y, int r, int c) {
        if (x < 0 || y < 0 || x >= r || y >= c || grid[x][y] == 0 || grid[x][y] == 2) {
            return false;
        }
        return true;
    }
    
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, +1};

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, set<pair<int,int>>& vis, int& currentArea) {
        if (!isValid(grid, i, j, m, n)) {
            return 0;
        }

        vis.insert({i, j});
        grid[i][j] = 2;  // Mark as visited

        int smallAns = 1;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            smallAns += dfs(grid, x, y, m, n, vis, currentArea);
        }

        return smallAns;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<pair<int,int>> vis;

        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isValid(grid, i, j, m, n)) {
                    vis.clear();  // Reset visited set for each new island
                    int currentArea = 0;
                    int smallAns = dfs(grid, i, j, m, n, vis, currentArea);
                    res = max(res, smallAns);
                }
            }
        }

        return res;
    }
};