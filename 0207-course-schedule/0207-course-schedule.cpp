class Solution {
public:
    
    bool dfs(unordered_map<int,vector<int>>&adj, int u, vector<bool>&visited, vector<bool>&inRec){
        
        visited[u] = true;
        inRec[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                if(dfs(adj, v, visited, inRec) == true)     return true;
            }else if(inRec[v] == true)    return true;
        }
        
        inRec[u] = false;
        return false;        
    }
    
    bool detectCycleDFS(int numCourses, vector<vector<int>>& prerequisites){
        int n = numCourses;
//          form graph
        unordered_map<int,vector<int>>adj;
        for(vector<int> &course : prerequisites){
            
            int u = course[1];
            int v = course[0];
            
            adj[u].push_back(v);
        }
        
        vector<bool>visited(n, false);
        vector<bool>inRec(n, false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(adj, i, visited, inRec) == true)     return true;
            }
        }
        
        return false;    
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool cycle = detectCycleDFS(numCourses, prerequisites);
        return !cycle;
    }
};