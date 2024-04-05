class Solution {
public:
    bool check(stack<char>& stk, char b) {
        if (!stk.empty()) {
            char a = stk.top();
            if ((a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z' && tolower(a) == b) ||
                (a >= 'a' && a <= 'z' && b >= 'A' && b <= 'Z' && toupper(a) == b))
                return true;
        }
        return false;
    }

    string makeGood(string s) {
        int n = s.length();
        stack<char> stk;

        for (int i = 0; i < n;) {
            while (i < n && !stk.empty() && check(stk, s[i])) {
                stk.pop();
                i++;
            }
            if (i < n)
                stk.push(s[i++]);
        }

        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};