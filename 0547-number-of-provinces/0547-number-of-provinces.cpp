class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<bool>&vis, int s, int n){
        
        vis[s] = true;
        
        for(int i = 0; i < n; i++){
            
            if(adj[s][i] == 1 && !vis[i])   dfs(adj, vis, i, n);
            
        }
        
        return;
        
    }
    int findCircleNum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<bool>vis(n, false);
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                
                ++count;
                
                dfs(mat, vis, i, n);
            }
            
        }
        
        return count;
        
    }
};