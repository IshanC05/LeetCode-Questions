class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, -1, 0, +1};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>>result(r, vector<int>(c, INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;
        
        pq.push({0, {0, 0}});
        result[0][0] = 0;
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            int dist = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            
            if(i == r - 1 && j == c - 1)    break;
            
            for(int k = 0; k < 4; k++){
                
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(x >= 0 && x < r && y >= 0 && y < c && result[x][y] > max(result[i][j], abs(heights[i][j] - heights[x][y]))){
                    result[x][y] = max(result[i][j], abs(heights[i][j] - heights[x][y]));
                    pq.push({result[x][y], {x, y}});
                }    
            }
        }
        
        return result[r - 1][c - 1];
    }
};