class Solution {
public:
    int M = 1e9+7;
    
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, +1};
    
    int t[51][51][51];
    
    int helper(int m, int n, int k, int i, int j){
        if(i < 0  || i == m || j < 0 || j == n)     return 1;
        if(k == 0)  return 0;
        
        if(t[k][i][j] != -1)    return t[k][i][j];
        
        long long res = 0;
        
        for(int l = 0; l < 4; l++){
            res = res + helper(m, n, k - 1, i + dx[l], j + dy[l]);
            res = res % M;
        }
        
        return t[k][i][j] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
        memset(t, -1, sizeof(t));
        return helper(m, n, maxMove, startRow, startCol);
    }
};