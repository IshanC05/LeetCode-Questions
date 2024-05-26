class Solution {
private:
    int MOD = 1000000007;

    int helper(int idx, int n, int absCount, int lateCount, vector<vector<vector<int>>>& memo) {
        if (absCount >= 2 || lateCount >= 3)
            return 0;
        
        if (idx == n)
            return 1;
        
        if (memo[idx][absCount][lateCount] != -1)
            return memo[idx][absCount][lateCount];

        int res = 0;
        res = (res + helper(idx + 1, n, absCount, 0, memo)) % MOD;
        res = (res + helper(idx + 1, n, absCount + 1, 0, memo)) % MOD;
        res = (res + helper(idx + 1, n, absCount, lateCount + 1, memo)) % MOD;

        return memo[idx][absCount][lateCount] = res;
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, n, 0, 0, memo);
    }
};