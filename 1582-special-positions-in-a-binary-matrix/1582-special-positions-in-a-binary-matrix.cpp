class Solution {
public:
    bool check(vector<vector<int>>& mat, int i, int j, int m, int n){
        
        int sum = 0;
        
        for(int k = 0; k < n; k++)
            sum += mat[i][k];
        
        if(sum > 1)     return false;
        
        sum = 0;
        
        for(int k = 0; k < m; k++)
            sum += mat[k][j];
        
        return !(sum > 1); 
    }
    
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        
        int res = 0;
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 1 && check(mat, i, j, m, n))  ++res;
                
            }
            
        }
        
        return res;        
    }
};