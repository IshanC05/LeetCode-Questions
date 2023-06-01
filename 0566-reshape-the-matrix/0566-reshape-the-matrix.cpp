class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size(), cols = mat[0].size();
        int total_elems = (rows * cols);
        
        if(total_elems != (r * c)){
            return mat;
        }
        
        vector<vector<int>>ans(r, vector<int>(c));
        
        int ni = 0, nj = 0;
        for(int oi = 0; oi < rows; oi++){
            for(int oj = 0; oj < cols; oj++){
                if(nj == c){
                    ++ni;
                    nj = 0;
                }
                ans[ni][nj++] = mat[oi][oj]; 
            }
        }
        return ans;
    }
};