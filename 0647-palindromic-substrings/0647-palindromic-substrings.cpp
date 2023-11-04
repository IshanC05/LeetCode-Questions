class Solution {
public:
    int dp[1001][1001];
    int countSubstrings(string s) {
        int n = s.size(), res = 0;

        // Initialize the dp array to all zeros
        memset(dp, 0, sizeof(dp));

        // Length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            ++res;
        }

        // Length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                ++res;
            }
        }

        // Length >= 3
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    ++res;
                }
            }
        }

        return res;
    }

};