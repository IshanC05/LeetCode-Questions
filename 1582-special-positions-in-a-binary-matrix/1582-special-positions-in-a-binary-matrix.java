class Solution {
    public int numSpecial(int[][] mat) {
        
        int m = mat.length, n = mat[0].length, res = 0;
        
        int rowCount[] = new int[m];
        
        int colCount[] = new int[n];
        
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
}