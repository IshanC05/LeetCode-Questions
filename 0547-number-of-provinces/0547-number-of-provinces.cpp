class Solution {
public:
    void dfs(vector<vector<int>>& arr, int s, vector<bool>& visited) {
        visited[s] = true;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[s][i] == 1 && !visited[i]) {
                dfs(arr, i, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                count++;
            }
        }

        return count;
    }

};