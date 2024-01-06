class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // form graph
        unordered_map<int, vector<int>>adj;
        vector<int>inDegree(n, 0);
        
        for(auto it : pre){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            ++inDegree[v];
        }
        
        queue<int>q;
        
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0)    q.push(i);
        }
        
        int nodeCount = 0;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            
            ++nodeCount;
            
            for(int &v : adj[u]){
                --inDegree[v];
                
                if(inDegree[v] == 0)
                    q.push(v);
            }
        }
        
        return nodeCount == n;
    }
};