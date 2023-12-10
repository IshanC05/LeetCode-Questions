class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>>res(n, vector<int>(m));
        
        int I = 0, J = 0;
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                res[I++][J] = matrix[i][j];
                
            }
            
            ++J;
            
            I = 0;
            
        }
        
        return res;
        
    }
};