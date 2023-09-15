class Solution {
public:
    int n;
//     void dfs(vector<vector<int>>& isConnected, int u, vector<bool>&visited){
        
//         visited[u] = true;
        
//         for(int v = 0; v < n; v++){
//             if(!visited[v] && isConnected[u][v] == 1){
//                 dfs(isConnected, v, visited);
//             }
//         }
//     }
    void bfs(vector<vector<int>>& isConnected, int s, vector<bool>&visited){
        
        queue<int>q;
        q.push(s);
        visited[s] = true;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            
            for(int v = 0; v < n; v++){
                if(!visited[v] && isConnected[u][v] == 1){
                    visited[v] = true;
                    q.push(v);
                }
            }
            
        }       
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        
        // Count Provinces through BFS
        int count = 0;
        vector<bool>visited(n, false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                // dfs(isConnected, i, visited);
                bfs(isConnected, i, visited);
                ++count;
            }
        }
        
        return count;
    }
};