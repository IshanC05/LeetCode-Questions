//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // find Indegree
        vector<int>inDeg(V, 0);
        for(int i = 0; i < V; i++){
            for(int &v : adj[i]){
                ++inDeg[v];
            }
        }
        
        // push inDegree = 0 to q
        queue<int>q;
        int count = 0;
        for(int i = 0; i < V; i++){
            if(inDeg[i] == 0){
                ++count;
                q.push(i);
            }
        }
        
        // Simple BFS
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v : adj[u]){
                --inDeg[v];
                
                if(inDeg[v] == 0){
                    ++count;
                    q.push(v);
                }
            }
        }
        
        return !(count == V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends