//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    class Node {
    public:
        int x;
        int y;
        int t;
    
        Node(int x, int y, int t) {
            this->x = x;
            this->y = y;
            this->t = t;
        }
    };
    
    bool isValid(int i, int j, int r, int c) {
        if (i < 0 || i == r || j < 0 || j == c) return false;
        return true;
    }
    
    int BFS(vector<vector<int>>& grid) {
        queue<Node> q;
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
    
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    Node n(i, j, 0);
                    q.push(n);
                }
            }
        }
    
        while (!q.empty()) {
            Node front = q.front();
            q.pop();
            int i = front.x;
            int j = front.y;
            int t = front.t;
            ans = max(ans, t);
    
            if (isValid(i + 1, j, row, col) && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                Node n1(i + 1, j, t + 1);
                q.push(n1);
            }
    
            if (isValid(i - 1, j, row, col) && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                Node n1(i - 1, j, t + 1);
                q.push(n1);
            }
    
            if (isValid(i, j + 1, row, col) && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                Node n1(i, j + 1, t + 1);
                q.push(n1);
            }
    
            if (isValid(i, j - 1, row, col) && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                Node n1(i, j - 1, t + 1);
                q.push(n1);
            }
        }
    
        return ans;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int minTime = BFS(grid);
    
        int row = grid.size();
        int col = grid[0].size();
    
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) return -1; // If there are still fresh oranges, return -1.
            }
        }
    
        return minTime;
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