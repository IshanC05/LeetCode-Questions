class Solution {
public:
    int t[101];

    int helper(string& s, int i, int n) {
        if (s[i] == '0') return 0;
        else if (i == n - 1 || i == n) return 1;

        if (t[i] != -1) return t[i];

        int res = helper(s, i + 1, n);

        if (i + 1 < n) {
            int num = ((s[i] - '0') * 10) + (s[i + 1] - '0');
            if (num <= 26) res += helper(s, i + 2, n);
        }

        return t[i] = res;
    }

    int numDecodings(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        return helper(s, 0, n);
    }
};