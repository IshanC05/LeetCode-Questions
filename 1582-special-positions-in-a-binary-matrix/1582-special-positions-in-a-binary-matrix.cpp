class Solution {
public:    
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size(), res = 0;
        
        vector<int>rowCount(m, 0), colCount(n, 0);
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 1){
                    
                    ++rowCount[i];
                    
                    ++colCount[j];
                    
                }
                
            }
            
        }
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1)  ++res;
                
            }
            
        }
        
        return res;        
    }
};