class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<int>rowOnesCount(m, 0), colOnesCount(n, 0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j] == 1){
                    ++rowOnesCount[i];
                    ++colOnesCount[j];
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int onesRow = rowOnesCount[i];
                int onesCol = colOnesCount[j];
                int zerosRow = n - rowOnesCount[i];
                int zerosCol = m - colOnesCount[j];
                
                grid[i][j] = onesRow + onesCol - (zerosRow + zerosCol);
                
            }
        }
        
        return grid;      
        
    }
};