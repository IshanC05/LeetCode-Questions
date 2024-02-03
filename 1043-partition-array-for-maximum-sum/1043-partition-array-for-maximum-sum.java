class Solution {
    public int[] t = new int[501];
    public int helper(int[] arr, int k, int idx, int n) {
        if (idx >= n) return 0;

        if (t[idx] != -1)   return t[idx];

        int maxE = arr[idx], res = 0;

        for (int len = 1; len <= k && idx + len <= n; len++) {
            maxE = Math.max(maxE, arr[idx + len - 1]);
            res = Math.max(res, (maxE * len) + helper(arr, k, idx + len, n));
        }

        return t[idx] = res;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        Arrays.fill(t, -1);
        return helper(arr, k, 0, arr.length);
    }
}