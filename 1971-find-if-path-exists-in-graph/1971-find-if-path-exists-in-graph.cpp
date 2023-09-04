class Solution {
public:
    
    bool BFS(unordered_map<int, vector<int>>&mp, int st, int e, vector<bool>&visited){
        
        queue<int>pendingNodes;
        
        pendingNodes.push(st);
        
        visited[st] = true;
        
        while(!pendingNodes.empty()){
            
            int front = pendingNodes.front();
            
            pendingNodes.pop();
            
            if(front == e)     return true;
            
            for(int i : mp[front]){
                
                if(!visited[i]){
                    
                    pendingNodes.push(i);
                    
                    visited[i] = true;
                    
                }
                
            }
            
        }
        
        return false;
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // create graph         
        unordered_map<int, vector<int>>mp;
        
        for(auto &edge : edges){
            
            int u = edge[0];
            int v = edge[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
            
        }
        
        //  create a visited array
        vector<bool>visited(n, false);
        
        return BFS(mp, source, destination, visited);
    }
};