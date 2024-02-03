class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int maxE = arr[i - 1];
            for (int len = 1; len <= k && i - len >= 0; len++) {
                maxE = max(maxE, arr[i - len]);
                dp[i] = max(dp[i], dp[i - len] + maxE * len);
            }
        }

        return dp[n];
    }
};