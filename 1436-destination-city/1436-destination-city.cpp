class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string, vector<string>>adj;
        
        for(vector<string> path : paths){
            
            string u = path[0];
            string v = path[1];
            
            adj[u].push_back(v);
        }
        
        for(vector<string>path : paths){
            
            string u = path[0];
            string v = path[1];
            
            if(adj.find(u) == adj.end())    return u;
            
            if(adj.find(v) == adj.end())    return v;
            
        }
        
        return "";
        
    }
};