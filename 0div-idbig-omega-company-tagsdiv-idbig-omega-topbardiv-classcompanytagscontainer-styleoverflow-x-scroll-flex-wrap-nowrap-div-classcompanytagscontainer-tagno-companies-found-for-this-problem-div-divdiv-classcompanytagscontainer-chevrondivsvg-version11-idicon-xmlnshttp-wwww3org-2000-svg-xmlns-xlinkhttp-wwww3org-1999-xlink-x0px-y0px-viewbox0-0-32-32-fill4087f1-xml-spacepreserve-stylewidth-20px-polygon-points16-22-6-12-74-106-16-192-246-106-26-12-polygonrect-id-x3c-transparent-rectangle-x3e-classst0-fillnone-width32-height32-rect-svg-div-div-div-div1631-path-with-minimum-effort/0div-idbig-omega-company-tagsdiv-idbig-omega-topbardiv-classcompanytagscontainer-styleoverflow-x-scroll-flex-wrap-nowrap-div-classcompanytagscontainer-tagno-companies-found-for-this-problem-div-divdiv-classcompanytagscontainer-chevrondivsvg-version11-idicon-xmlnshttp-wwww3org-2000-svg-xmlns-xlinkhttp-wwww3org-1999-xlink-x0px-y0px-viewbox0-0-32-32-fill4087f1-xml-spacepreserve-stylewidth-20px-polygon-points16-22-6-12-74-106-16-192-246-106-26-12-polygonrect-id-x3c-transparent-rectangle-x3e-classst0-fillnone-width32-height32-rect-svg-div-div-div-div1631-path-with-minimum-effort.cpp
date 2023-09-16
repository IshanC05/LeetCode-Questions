class Solution {
public:
    bool dfs(int i, int j, int diff, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        
        if (i == m - 1 && j == n - 1) {
            return true;
        }
        
        visited[i][j] = true;
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (const auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && abs(heights[x][y] - heights[i][j]) <= diff) {
                if (dfs(x, y, diff, heights, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int left = 0;
        int right = INT_MAX;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            
            if (dfs(0, 0, mid, heights, visited)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
