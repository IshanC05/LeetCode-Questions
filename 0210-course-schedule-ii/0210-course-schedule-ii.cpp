class Solution {
public:
    
    void dfs(unordered_map<int,vector<int>>&adj, int u, vector<bool>&visited, stack<int>&st){
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited, st);
            }
        }
        
        st.push(u);
    }
    
    vector<int>topologicalSortDFS(unordered_map<int,vector<int>>&adj, int n){
        vector<bool>visited(n, false);
        vector<int>ans;
        stack<int>st;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj, i, visited, st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
    
    bool dfsCycle(unordered_map<int,vector<int>>&adj, int u, vector<bool>&visited, vector<bool>&inRec){
        
        visited[u] = true;
        inRec[u] = true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                if(dfsCycle(adj, v, visited, inRec))    return true;
            }
            else if(inRec[v])   return true;
        }
        
        inRec[u] = false;
        return false;
    }
    
    bool checkCycle(unordered_map<int,vector<int>>&adj, int n){
        
        vector<bool>visited(n, false);
        vector<bool>inRec(n, false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfsCycle(adj, i, visited, inRec))    return true;
            }
        }
        
        return false;        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        // form graph
        unordered_map<int,vector<int>>adj;
        for(vector<int>&c : prerequisites){
            
            int u = c[1];
            int v = c[0];
            
            adj[u].push_back(v);
        }  
        
        if(checkCycle(adj, n))  return {};
        
        return topologicalSortDFS(adj, n);
    }
};