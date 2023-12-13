class Solution {
    public int numSpecial(int[][] mat) {
        
        int m = mat.length, n = mat[0].length, res = 0;
        
        List<Integer> rowCount = new ArrayList<>(Collections.nCopies(m, 0));
        
        List<Integer> colCount = new ArrayList<>(Collections.nCopies(n, 0));
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 1){
                    
                    rowCount.set(i, rowCount.get(i) + 1);
                    
                    colCount.set(j, colCount.get(j) + 1);
                    
                }
                
            }
            
        }
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 1 && rowCount.get(i) == 1 && colCount.get(j) == 1)  ++res;
                
            }
            
        }
        
        return res;
        
    }
}