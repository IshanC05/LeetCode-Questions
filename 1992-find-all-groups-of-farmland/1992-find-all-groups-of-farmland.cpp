class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int r = land.size();
        int c = land[0].size();
        
        vector<vector<int>> res;
        
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
                    
                    res.push_back({i, j, ei, ej});
                    
                    for(int ti = i; ti <= ei; ti++){
                        for(int tj = j; tj <= ej; tj++){
                            land[ti][tj] = 0;
                        }
                    }
                    
                }
            }
        }
        
        return res;
    }
};