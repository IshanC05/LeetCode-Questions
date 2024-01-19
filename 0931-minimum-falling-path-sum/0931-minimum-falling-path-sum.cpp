class Solution {
public:
    int t[101][101];
    int dfs(vector<vector<int>>& mat, int i, int j, int n){
        if(i == n - 1)  return t[i][j] = mat[i][j];
        
        if(t[i][j] != 1e8)  return t[i][j];
        
        int sum = INT_MAX;
        
        int dx[3] = {1, 1, 1};
        int dy[3] = {-1, 0, 1};
        
        for(int k = 0; k < 3; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x >= 0 && x < n && y >= 0 && y < n){
                sum = min(sum, mat[i][j] + dfs(mat, x, y, n));
            }
        }
        
        return t[i][j] = sum;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j] = 1e8; 
            }
        }
        
        int res = INT_MAX;
        
        for(int j = 0; j < n; j++){
            res = min(res, dfs(mat, 0, j, n));
        }
        
        return res;
    }
};