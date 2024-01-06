class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>&color, int currNode, int currColor){
        color[currNode] = currColor;
        
        for(int &v : graph[currNode]){
            if(color[v] == currColor)   return false;
            
            if(color[v] == -1){
                int colorV = 1 - currColor;
                
                if(dfs(graph, color, v, colorV) == false)   return false;
            }
        }
        
        return true;
    }
    bool bfs(vector<vector<int>>& graph, vector<int>&color, int currNode, int currColor){
        queue<int>q;
        q.push(currNode);
        color[currNode] = currColor;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            
            for(int &v : graph[u]){
                
                if(color[v] == color[u])   return false;
                
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int>color(n, -1);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                // if(dfs(graph, color, i, 0) == false)    return false;
                if(bfs(graph, color, i, 0) == false)    return false;
            }
        }
        
        return true;
    }
};