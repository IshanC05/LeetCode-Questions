class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxL = 0;

        string res;

        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {

                if (gap == 0) {
                    t[i][j] = 1;
                } else if (gap == 1) {
                    t[i][j] = (s[i] == s[j]);
                } else if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = 1;
                }

                if (t[i][j] && maxL < j - i + 1) {
                    maxL = j - i + 1;
                    res = s.substr(i, maxL);
                }
            }
        }

        return res;
    }
};