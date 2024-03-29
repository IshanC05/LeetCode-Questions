//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    
	    vector<vector<int>>res(n, vector<int>(m, INT_MAX));
	    
	    queue<pair<int, int>>q;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            
	            if(grid[i][j] == 1){
	                
	                res[i][j] = 0;
	                
	                q.push({i, j});
	            }
	            
	        }
	    }
	    
	    int dx[4] = {-1, 0, +1, 0};
	    int dy[4] = {0, -1, 0, +1};
	    
	    while(!q.empty()){
	        
	        int X = q.front().first;
	        int Y = q.front().second;
	        int dist = res[X][Y];
	        q.pop();
	        
	        for(int k = 0; k < 4; k++){
	            
	            int x = X + dx[k];
	            int y = Y + dy[k];
	            
	            if(x >= 0 && x < n && y >= 0 && y < m && res[x][y] > 1 + dist){
	                
	                res[x][y] = min(res[x][y], 1 + dist);
	                
	                q.push({x, y});
	                
	            }
	        }
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends