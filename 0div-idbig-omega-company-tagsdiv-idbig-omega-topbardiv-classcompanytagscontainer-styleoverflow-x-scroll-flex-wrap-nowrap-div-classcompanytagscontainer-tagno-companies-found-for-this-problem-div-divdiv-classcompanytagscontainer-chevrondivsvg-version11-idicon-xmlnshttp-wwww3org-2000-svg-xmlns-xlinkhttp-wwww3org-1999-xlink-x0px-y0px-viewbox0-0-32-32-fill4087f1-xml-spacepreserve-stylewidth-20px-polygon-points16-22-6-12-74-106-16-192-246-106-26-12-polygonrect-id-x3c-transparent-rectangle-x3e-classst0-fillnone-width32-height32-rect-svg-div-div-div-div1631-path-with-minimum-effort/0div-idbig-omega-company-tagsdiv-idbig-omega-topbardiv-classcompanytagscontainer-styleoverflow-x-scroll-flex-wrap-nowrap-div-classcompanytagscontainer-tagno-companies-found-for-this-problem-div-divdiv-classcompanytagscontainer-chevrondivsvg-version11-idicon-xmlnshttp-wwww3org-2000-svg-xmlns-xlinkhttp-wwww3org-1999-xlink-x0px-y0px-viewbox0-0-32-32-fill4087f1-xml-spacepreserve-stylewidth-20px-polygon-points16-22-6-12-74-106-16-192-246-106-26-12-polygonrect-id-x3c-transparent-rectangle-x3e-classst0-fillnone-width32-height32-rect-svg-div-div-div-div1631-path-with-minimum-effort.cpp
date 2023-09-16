class Solution {
public:
    
    bool dfs(int i, int j, int m, int n, int diff, vector<vector<int>>& v, vector<vector<int>>& h) {
        if (i == m - 1 && j == n - 1) {
            return true;
        }

        v[i][j] = 1;

        bool path = false;

        if (i + 1 < m && !v[i + 1][j] && abs(h[i][j] - h[i + 1][j]) <= diff) {
            path = path || dfs(i + 1, j, m, n, diff, v, h);
        }

        if (j + 1 < n && !v[i][j + 1] && abs(h[i][j] - h[i][j + 1]) <= diff) {
            path = path || dfs(i, j + 1, m, n, diff, v, h);
        }

        if (i - 1 >= 0 && !v[i - 1][j] && abs(h[i][j] - h[i - 1][j]) <= diff) {
            path = path || dfs(i - 1, j, m, n, diff, v, h);
        }

        if (j - 1 >= 0 && !v[i][j - 1] && abs(h[i][j] - h[i][j - 1]) <= diff) {
            path = path || dfs(i, j - 1, m, n, diff, v, h);
        }

        return path;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, h = 1e6, ans = h, m = heights.size(), n = heights[0].size();

        while (l <= h) {
            int mid = l + (h - l) / 2;
            vector<vector<int>> v(m, vector<int>(n, 0));

            if (dfs(0, 0, m, n, mid, v, heights)) {
                ans = min(ans, mid);
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

};