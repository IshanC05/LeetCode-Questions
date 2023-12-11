//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        
        bool isFreshPresent = false;
        
        queue<pair<pair<int, int>, int>>q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 2){
                    
                    grid[i][j] = 0;
                    
                    q.push({{i, j}, 0});
                    
                }
                
                if(grid[i][j] == 1)     isFreshPresent = true;
            }
        }
        
        if(!isFreshPresent)     return 0;
        
        int res = INT_MIN;
        
        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = {0, -1, 0, +1};
        
        while(!q.empty()){
            
            int X = q.front().first.first;
            int Y = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            res = max(res, time);
            
            for(int k = 0; k < 4; k++){
                
                int x = X + dx[k];
                int y = Y + dy[k];
                
                if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                    
                    grid[x][y] = 0;
                    
                    q.push({{x, y}, 1 + time});
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)     return -1;
            }
        }
        
        return res == INT_MIN ? 0 : res;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends