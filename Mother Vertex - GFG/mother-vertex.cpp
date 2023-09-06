//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    int findMotherVertex(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int motherVertex = 0;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited, motherVertex);
                motherVertex = i;
            }
        }
        
    
        fill(visited.begin(), visited.end(), false); 
        dfs(adj, motherVertex, visited, motherVertex);
        
        for (bool isVisited : visited) {
            if (!isVisited) {
                return -1; 
            }
        }
        
        return motherVertex;
    }
    
    void dfs(vector<int> adj[], int s, vector<bool>& visited, int motherVertex) {
        visited[s] = true;
        
        for (int v : adj[s]) {
            if (!visited[v]) {
                dfs(adj, v, visited, motherVertex);
            }
        }
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends