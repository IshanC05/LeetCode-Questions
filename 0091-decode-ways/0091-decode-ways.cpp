class Solution {
public:
    bool isValid(string &s, int i) {
        if (i + 1 < s.size()) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            return (a * 10 + b) <= 26;
        }
        return false;
    }

    int t[101];
    int helper(string s, int i, int n) {
        if (i == n)  return 1;  // Reach the end of the string
        if (s[i] == '0')  return 0;  // '0' cannot be decoded alone

        if(t[i] != -1)  return t[i];
        
        int single = helper(s, i + 1, n);
        int combine = 0;

        if (i + 1 < n && isValid(s, i)) {
            combine = helper(s, i + 2, n);
        }

        return t[i] = single + combine;
    }

    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        memset(t, -1, sizeof(t));
        return helper(s, 0, n);
    }
};