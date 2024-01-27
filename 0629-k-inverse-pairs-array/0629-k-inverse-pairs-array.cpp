class Solution {
public:
    int M = 1e9+7;
    const int MAXN = 1001;

    int kInversePairs(int n, int k) {
        int t[MAXN][MAXN];
        memset(t, 0, sizeof(t));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0) {
                    t[i][j] = 1;
                } else if (i == 0) {
                    t[i][j] = 0;
                } else {
                    for (int inv = 0; inv <= min(j, i - 1); inv++) {
                        t[i][j] = (t[i][j] + t[i - 1][j - inv]) % M;
                    }
                }
            }
        }

        return t[n][k];
    }
};