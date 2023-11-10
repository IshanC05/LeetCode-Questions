class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&graph, int s, unordered_set<int>&vis, vector<int>&ans){
        
        if(vis.find(s) != vis.end())    return;
        
        vis.insert(s);
        
        ans.push_back(s);
        
        for(auto &v : graph[s]){
            
            if(vis.find(v) == vis.end()){
                
                dfs(graph, v, vis, ans);
            }
            
        }
        
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int,vector<int>>graph;
        
        int n = adjacentPairs.size();
        
        for(int i = 0; i < n; i++){
            
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
        
        vector<int>ans;
        unordered_set<int>vis;
        
        for(auto it : graph){
            
            int u = it.first;
            
            if(it.second.size() == 1){
                
                dfs(graph, u, vis, ans);
                
            }
            
        }
        
        return ans;
    }
};