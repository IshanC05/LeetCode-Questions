class Solution {
public:
    int t[501][501];
    int helper(vector<int>& arr, int k, int idx, int n) {
        if (idx >= n) return 0;

        if (t[idx][k] != -1) return t[idx][k];

        int maxE = arr[idx], res = 0;

        for (int len = 1; len <= k && idx + len <= n; len++) {
            maxE = max(maxE, arr[idx + len - 1]);
            res = max(res, (maxE * len) + helper(arr, k, idx + len, n));
        }

        return t[idx][k] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t, -1, sizeof(t));
        return helper(arr, k, 0, arr.size());
    }
};