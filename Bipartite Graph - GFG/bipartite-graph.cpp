//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);
    
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(adj, i, 0, color))
                    return false;
            }
        }
    
        return true;
    }
    
    bool bfs(vector<int> adj[], int start, int startColor, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = startColor;
    
        while (!q.empty()) {
            int u = q.front();
            q.pop();
    
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    
        return true;
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends