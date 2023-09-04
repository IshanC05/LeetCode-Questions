class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);

        for (const auto& it : trust) {
            int u = it[0];
            int v = it[1];
            outDegree[u]++;
            inDegree[v]++;
        }

        for (int i = 1; i <= n; i++) {
            // A judge has in-degree n - 1 and out-degree 0.
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};