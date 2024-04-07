class Solution {
public:
    int t[101][101];

    bool helper(int idx, int openCount, string& s) {
        if (idx == s.length()) {
            return (openCount == 0);
        }
        if (t[idx][openCount] != -1) {
            return t[idx][openCount] == 1;
        }
        bool isValid = false;
        if (s[idx] == '*') {
            isValid |= helper(idx + 1, openCount + 1, s);
            if (openCount > 0) {
                isValid |= helper(idx + 1, openCount - 1, s);
            }
            isValid |= helper(idx + 1, openCount, s);
        } else {
            if (s[idx] == '(') {
                isValid = helper(idx + 1, openCount + 1, s);
            } else if (openCount > 0) {
                isValid = helper(idx + 1, openCount - 1, s);
            }
        }

        t[idx][openCount] = isValid ? 1 : 0;
        return isValid;
    }

    bool checkValidString(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        return helper(0, 0, s);
    }
};