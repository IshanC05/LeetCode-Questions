class Solution {
public:
    
    void dfs(unordered_map<int, vector<int>>&adj, int u, vector<bool>&visited){
        
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // form graph
        int n = isConnected.size();
        unordered_map<int, vector<int>>adj;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    
                    int u = i;
                    int v = j;
                    
                    adj[u].push_back(v);
                    
                }
            }
        }
        
        // Count Provinces through DFS
        int count = 0;
        vector<bool>visited(n, false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj, i, visited);
                ++count;
            }
        }
        
        return count;
    }
};