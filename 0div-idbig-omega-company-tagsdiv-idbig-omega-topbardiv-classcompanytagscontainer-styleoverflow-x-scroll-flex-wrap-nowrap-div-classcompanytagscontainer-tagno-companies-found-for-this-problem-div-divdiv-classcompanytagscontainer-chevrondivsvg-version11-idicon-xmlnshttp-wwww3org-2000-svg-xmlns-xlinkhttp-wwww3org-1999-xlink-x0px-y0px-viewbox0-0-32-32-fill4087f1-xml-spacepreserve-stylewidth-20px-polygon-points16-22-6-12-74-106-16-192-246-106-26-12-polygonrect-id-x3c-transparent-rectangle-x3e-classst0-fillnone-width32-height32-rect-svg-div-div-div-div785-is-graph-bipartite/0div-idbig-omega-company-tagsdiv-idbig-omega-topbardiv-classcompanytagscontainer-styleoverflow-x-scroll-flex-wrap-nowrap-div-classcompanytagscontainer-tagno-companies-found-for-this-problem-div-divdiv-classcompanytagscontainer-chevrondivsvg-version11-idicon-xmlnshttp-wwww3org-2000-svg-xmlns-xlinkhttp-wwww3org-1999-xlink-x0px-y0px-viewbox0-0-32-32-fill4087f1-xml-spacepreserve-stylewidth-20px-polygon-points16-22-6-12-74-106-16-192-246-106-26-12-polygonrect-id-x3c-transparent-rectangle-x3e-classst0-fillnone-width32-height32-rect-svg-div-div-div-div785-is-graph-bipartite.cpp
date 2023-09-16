class Solution {
public:
    
    bool bfs(vector<vector<int>>& adj, int start, int startColor, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = startColor;
    
        while (!q.empty()) {
            int u = q.front();
            q.pop();
    
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    
        return true;
    }

	bool isBipartite(vector<vector<int>>& adj) {

	    int V = adj.size();
        
	    vector<int>color(V, -1);
	    
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            if(bfs(adj, i, 1, color) == false)  return false;
	        }
	    }
	    
	    return true;
	}
};