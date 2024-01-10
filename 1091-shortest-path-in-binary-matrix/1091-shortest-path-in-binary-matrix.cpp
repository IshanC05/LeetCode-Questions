class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    int dx[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, +1, +1, +1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 0 || grid[0][0] != 0)   return -1;
        
        queue<P>pq;
        vector<vector<int>>result(n, vector<int>(n, INT_MAX));
        
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()){
                
            auto curr = pq.front();
            pq.pop();
            
            int dist = curr.first;
            int X = curr.second.first;
            int Y = curr.second.second;

            for(int k = 0; k < 8; k++){

                int x = X + dx[k];
                int y = Y + dy[k];

                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && result[x][y] > dist + 1 ){
                    result[x][y] = dist + 1;
                    pq.push({result[x][y], {x, y}});
                }
            }
        }
        
        if(result[n - 1][n - 1] == INT_MAX) 
            return -1;
        
        return result[n - 1][n - 1] + 1;
    }
};