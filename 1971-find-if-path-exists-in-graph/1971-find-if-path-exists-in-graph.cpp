class Solution {
public:
    
    bool dfs(unordered_map<int, vector<int>>&mp, int st, int e, vector<bool>&visited){
        
        // reached destination ? return true          
        if(st == e)     return true;
        
        //  source already visited ? return false         
        if(visited[st]) return false;
        
        visited[st] = true;
        
        for(int node : mp[st]){
            
            if(dfs(mp, node, e, visited))   return true;
            
        }
        
        return false;
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // create a graph
        
        unordered_map<int, vector<int>>mp;
        
        for(auto &edge : edges){
            
            int u = edge[0];
            int v = edge[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
            
        }
        
        //  create a visited array
        vector<bool>visited(n, false);
        
        return dfs(mp, source, destination, visited);
    }
};