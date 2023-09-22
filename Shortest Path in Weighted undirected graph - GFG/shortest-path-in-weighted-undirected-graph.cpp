//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // form graph
        unordered_map<int, vector<pair<int,int>>>adj;
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int>parent(n + 1);
        vector<int>result(n + 1, INT_MAX);
        set<pair<int,int>>st;
        
        result[1] = 0;
        
        st.insert({0, 1});
        
        for(int i = 1; i <= n; i++) parent[i] = i;
        
        while(st.size() != 0){
            
            auto &it = *st.begin();
            int dist = it.first;
            int u = it.second;
            
            st.erase({dist, u});
            
            for(auto &v : adj[u]){
                
                int node = v.first;
                int d = v.second;
                
                if(result[node] > dist + d){
                    st.erase({result[node], node});
                    result[node] = d + dist;
                    st.insert({result[node], node});
                    parent[node] = u;
                }
            }
        }
        
        vector<int> path;
        int node = n;
        
        if(result[node] == INT_MAX)
            return {-1};
        
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(begin(path), end(path));
		return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends