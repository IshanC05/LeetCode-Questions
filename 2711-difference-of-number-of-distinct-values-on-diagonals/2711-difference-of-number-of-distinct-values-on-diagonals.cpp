class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>>ans(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                unordered_set<int>left, right;
                int r = i - 1, c = j - 1;
                
                while(r >= 0 and c >= 0){
                    left.insert(grid[r--][c--]);
                }
                
                r = i + 1, c = j + 1;
                
                while(r < row and c < col){
                    right.insert(grid[r++][c++]);
                }
                
                int t1 = left.size(), t2 = right.size();
                ans[i][j] = abs(t1 - t2);
            }
        }
        return ans;
    }
};