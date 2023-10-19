//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int BFS(vector<int> adj[], int x, vector<bool>&vis, int n){
	    
	    int level = 0;
	    queue<int>q;
	    q.push(0);
	    
	    vis[0] = true;
	    
	    while(!q.empty()){
	    
	        int qSize = q.size();
	        
	        for(int i = 0; i < qSize; i++){
	            
	            int u = q.front();
	            q.pop();
	            
	            for(auto &v : adj[u]){
	                
	                if(!vis[v]){
	                    q.push(v);
	                    vis[v] = true;
	                }
	            }
	            
	            if(u == x)  return level;
	        }
	        
	        ++level;
	    }
	    
	    return -1;
	}
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool>vis(V, false);
	    
	    return BFS(adj, X, vis, V);
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends