class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&adj, vector<bool>&vis, int s){
        
        vis[s] = true;
        
        for(int &v : adj[s]){
            
            if(!vis[v])     dfs(adj, vis, v);
            
        }
        
        return;
        
    }
    int findCircleNum(vector<vector<int>>& mat) {
        
        // form graph
        unordered_map<int, vector<int>>adj;
        
        int n = mat.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                if(mat[i][j] == 1){
                    
                    int u = i;
                    int v = j;
                    
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    
                }
                
            }
        }
        
        vector<bool>vis(n, false);
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                
                ++count;
                
                dfs(adj, vis, i);
            }
            
        }
        
        return count;
        
    }
};