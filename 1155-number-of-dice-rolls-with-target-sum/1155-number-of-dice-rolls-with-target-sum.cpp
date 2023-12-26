class Solution {
public:    
    int numRollsToTarget(int n, int k, int target) {
        int M = 1e9 + 7;
        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));

        for (int j = 1; j <= k && j <= target; j++) {
            t[1][j] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int l = 1; l <= k && l < j; l++) {
                    t[i][j] = (t[i][j] + t[i - 1][j - l]) % M;
                }
            }
        }

        return t[n][target];
    }
};