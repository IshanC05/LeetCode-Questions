//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // bool dfs(vector<int> adj[], int u, vector<bool>&visited, int parent){
        
    //     visited[u] = true;
        
    //     for(int &v : adj[u]){
            
    //         if(!visited[v]){
                
    //             if(dfs(adj, v, visited, u) == true)     return true;
    //         }
    //         else if(v != parent)    return true;
    //     }
        
    //     return false;
    // }
    
    bool bfs(vector<int> adj[], int U, vector<bool>&visited, int parent){
        
        visited[U] = true;
        
        queue<pair<int,int>>q;
        
        q.push({U, parent});
        
        while(!q.empty()){
            
            pair<int,int>p1 = q.front();
            
            q.pop();
            
            int u = p1.first;
            
            int p = p1.second;
            
            for(int &v : adj[u]){
                
                if(!visited[v]){
                    
                    visited[v] = true;
                    
                    q.push({v, u});
                }
                
                else if(v != p)     return true;
            }
            
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V, false);
        
        for(int i = 0; i < V; i++){
            
            if(!visited[i]){
                
                // if(dfs(adj, i, visited, -1))    return true;
                
                if(bfs(adj, i, visited, -1))    return true;
            }
            
        }
        
        return false;    
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends