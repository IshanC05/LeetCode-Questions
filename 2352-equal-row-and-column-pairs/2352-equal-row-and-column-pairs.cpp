class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        int res = 0;
        int n = grid.size();
        for(vector<int> row : grid){
            ++mp[row];
        }
        
        for(int i = 0; i < n; i++){
            vector<int>cols;
            for(int j = 0; j < n; j++){
                cols.push_back(grid[j][i]);
            }
            res += mp[cols];
        }
        
        return res;
    }
};