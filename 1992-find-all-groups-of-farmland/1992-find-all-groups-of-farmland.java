class Solution {
    public int[][] findFarmland(int[][] land) {
        int r = land.length;
        int c = land[0].length;
        
        List<int[]> list = new ArrayList<>();
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(land[i][j] == 1){
                    
                    land[i][j] = 0;
                    
                    int ei = i, ej = j;
                    
                    while(ei + 1 < r && land[ei + 1][j] == 1){
                        ++ei;    
                    }
                    
                    while(ej + 1 < c && land[i][ej + 1] == 1){
                        ++ej;    
                    }                   
                    
                    list.add(new int[]{i, j, ei, ej});
                    
                    for(int ti = i; ti <= ei; ti++){
                        for(int tj = j; tj <= ej; tj++){
                            land[ti][tj] = 0;
                        }
                    }
                    
                }
            }
        }
        
        int[][] res = list.toArray(new int[list.size()][]);
        
        return res;
    }
}