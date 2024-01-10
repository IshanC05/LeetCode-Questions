class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<bool>rows(m, true), cols(n, true);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 0){
                    rows[i] = false;
                    cols[j] = false;
                }
                
            }
        }
        
        for(int i = 0; i < m; i++){
            if(!rows[i])    for(int j = 0; j < n; j++)  mat[i][j] = 0;    
        }
        
        for(int j = 0; j < n; j++){
            if(!cols[j])    for(int i = 0; i < m; i++)  mat[i][j] = 0;
        }
        
        return;
    }
};