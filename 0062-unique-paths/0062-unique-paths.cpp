class Solution {
public:
    int t[101][101];
    int helper(int i, int j, int r, int c){
        if(i == r - 1 && j == c - 1)     return 1;
        if(i < 0 || i >= r || j < 0 || j >= c)  return 0;
        
        if(t[i][j] != -1)   return t[i][j];
        
        int down = helper(i + 1, j, r, c);
        int right = helper(i, j + 1, r, c);
        
        return t[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        return helper(0, 0, m, n);
    }
};