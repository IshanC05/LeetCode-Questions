class Solution {
    public int[][] findFarmland(int[][] land) {
        int r = land.length;
        int c = land[0].length;
        
        List<int[]> list = new ArrayList<>();
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(land[i][j] == 1){
                    
                    int x = i, y = j;
                                        
                    for(x = i; x < r && land[x][j] == 1; x++){
                        for(y = j; y < c && land[x][y] == 1; y++){
                            land[x][y] = 0;
                        }
                    }
                    
                    list.add(new int[]{i, j, x - 1, y - 1});
                }
            }
        }
        
        return list.toArray(new int[list.size()][]);
    }
}