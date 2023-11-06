class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxL = 0;
        string res;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            int sz = 1;
            if (maxL < sz) {
                maxL = sz;
                res = s[i];
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                int sz = 2;
                if (maxL < sz) {
                    maxL = sz;
                    res = s.substr(i, 2);
                }
            }
        }

        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    int currL = j - i + 1;
                    if (maxL < currL) {
                        maxL = currL;
                        res = s.substr(i, currL);
                    }
                }
            }
        }

        return res;
    }

};