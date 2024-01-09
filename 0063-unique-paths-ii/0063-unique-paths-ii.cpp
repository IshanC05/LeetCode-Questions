class Solution {
public:
    int t[101][101];
    int helper(vector<vector<int>>& grid, int i, int j, int r, int c){
        if(i == r - 1 && j == c - 1)    return 1;
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 1)   return 0;
        
        if(t[i][j] != -1)   return t[i][j];
        
        int down = helper(grid, i + 1, j, r, c);
        int right = helper(grid, i, j + 1, r, c);
        
        return t[i][j] = (down + right);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if(grid[r - 1][c - 1] == 1)     return 0;
        memset(t, -1, sizeof(t));
        return helper(grid, 0, 0, r, c);
    }
};