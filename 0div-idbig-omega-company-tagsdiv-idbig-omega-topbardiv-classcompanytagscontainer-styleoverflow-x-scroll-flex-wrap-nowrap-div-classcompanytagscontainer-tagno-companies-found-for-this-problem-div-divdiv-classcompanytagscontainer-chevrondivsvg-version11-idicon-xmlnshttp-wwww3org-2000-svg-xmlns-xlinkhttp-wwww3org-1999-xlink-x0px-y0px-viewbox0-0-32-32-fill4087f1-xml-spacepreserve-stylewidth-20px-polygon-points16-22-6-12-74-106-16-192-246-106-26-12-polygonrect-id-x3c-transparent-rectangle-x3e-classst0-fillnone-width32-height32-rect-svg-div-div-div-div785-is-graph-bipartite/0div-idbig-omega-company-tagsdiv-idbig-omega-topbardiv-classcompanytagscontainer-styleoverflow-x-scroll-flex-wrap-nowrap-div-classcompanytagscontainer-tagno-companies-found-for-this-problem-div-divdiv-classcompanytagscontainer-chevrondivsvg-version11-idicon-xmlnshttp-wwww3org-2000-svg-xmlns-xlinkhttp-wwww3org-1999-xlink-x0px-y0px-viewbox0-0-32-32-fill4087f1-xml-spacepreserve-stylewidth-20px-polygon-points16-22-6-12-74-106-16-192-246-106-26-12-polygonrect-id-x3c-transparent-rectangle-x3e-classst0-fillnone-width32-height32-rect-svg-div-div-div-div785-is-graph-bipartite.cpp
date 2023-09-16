class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj, int u, int uColor, vector<int>&color){
        
        color[u] = uColor;
        
        for(int &v : adj[u]){
            
            if(color[v] == uColor)  return false;
            
            if(color[v] == -1){
                
                int neighbourColor = 1 - uColor;
                
                if(dfs(adj, v, neighbourColor, color) == false)     return false;
            }
        }
        return true;
    }

	bool isBipartite(vector<vector<int>>& adj) {
	    // Code here
	    int V = adj.size();
        
	    vector<int>color(V, -1);
	    
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            if(dfs(adj, i, 1, color) == false)  return false;
	        }
	    }
	    
	    return true;
	}
};