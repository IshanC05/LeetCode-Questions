class Solution {
public:
private:
    int t[100005][27];
    
    int helper(int idx, const string& s, int k, int lastAscii) {
        if (idx == s.length())
            return 0;

        if (t[idx][lastAscii] != -1)
            return t[idx][lastAscii];
        
        int res = helper(idx + 1, s, k, lastAscii);
        
        int currAscii = s[idx] - 'a';
        
        if (lastAscii == 26 || abs(lastAscii - currAscii) <= k)
            res = max(res, 1 + helper(idx + 1, s, k, currAscii));
        
        return t[idx][lastAscii] = res;
    }
    
public:
    int longestIdealString(const string& s, int k) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        
        return helper(0, s, k, 26);
    }
};