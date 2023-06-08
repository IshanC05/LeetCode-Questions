class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                count = (grid[r][c] < 0) ? ++count : count;
            }
        }
        return count;
    }
};