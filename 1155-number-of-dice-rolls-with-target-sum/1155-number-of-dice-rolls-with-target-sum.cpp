class Solution {
public:    
    int numRollsToTarget(int n, int k, int target) {
        int M = 1e9 + 7;
        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));

        t[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int l = 1; l <= k; l++) {
                    if(j - l >= 0)  t[i][j] = (t[i][j] + t[i - 1][j - l]) % M;
                }
            }
        }

        return t[n][target];
    }
};